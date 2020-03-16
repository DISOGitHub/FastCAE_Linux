// Created on: 2017-04-21
// Created by: Alexander Bobkov
// Copyright (c) 2017 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _BRepTools_History_HeaderFile
#define _BRepTools_History_HeaderFile

#include <NCollection_Handle.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>

class BRepTools_History;
DEFINE_STANDARD_HANDLE(BRepTools_History, Standard_Transient)

//! The history keeps the following relations between the input shapes
//! (S1, ..., Sm) and output shapes (T1, ..., Tn):
//! 1) an output shape Tj is generated from an input shape Si: Tj <= G(Si);
//! 2) a output shape Tj is modified from an input shape Si: Tj <= M(Si);
//! 3) an input shape (Si) is removed: R(Si) == 1.
//!
//! The relations are kept only for shapes of types vertex, edge, face, and
//! solid.
//!
//! The last relation means that:
//! 1) shape Si is not an output shape and
//! 2) no any shape is generated or modified (produced) from shape Si:
//! R(Si) == 1 ==> Si != Tj, G(Si) == 0, M(Si) == 0.
//!
//! No any shape could be generated and modified from the same shape
//! simultaneously: sets G(Si) and M(Si) are not intersected
//! (G(Si) ^ M(Si) == 0).
//!
//! Each output shape should be:
//! 1) an input shape or
//! 2) generated or modified from an input shape (even generated from the
//!   implicit null shape if necessary):
//!   Tj == Si V (exists Si that Tj <= G(Si) U M(Si)).
//!
//! Recommendations to choose between relations 'generated' and 'modified':
//! 1) a shape is generated from input shapes if it dimension is greater or
//!   smaller than the dimensions of the input shapes;
//! 2) a shape is generated from input shapes if these shapes are also output
//!   shapes;
//! 3) a shape is generated from input shapes of the same dimension if it is
//!   produced by joining shapes generated from these shapes;
//! 4) a shape is modified from an input shape if it replaces the input shape by
//!   changes of the location, the tolerance, the bounds of the parametrical
//!   space (the faces for a solid), the parametrization and/or by applying of
//!   an approximation;
//! 5) a shape is modified from input shapes of the same dimension if it is
//!   produced by joining shapes modified from these shapes.
//!
//! Two sequential histories:
//! - one history (H12) of shapes S1, ..., Sm to shapes T1, ..., Tn and
//! - another history (H23) of shapes T1, ..., Tn to shapes Q1, ..., Ql
//! could be merged to the single history (H13) of shapes S1, ..., Sm to shapes
//! Q1, ..., Ql.
//!
//! During the merge:
//! 1) if shape Tj is generated from shape Si then each shape generated or
//!   modified from shape Tj is considered as a shape generated from shape Si
//!   among shapes Q1, ..., Ql:
//!   Tj <= G12(Si), Qk <= G23(Tj) U M23(Tj) ==> Qk <= G13(Si).
//! 2) if shape Tj is modified from shape Si, shape Qk is generated from shape
//!   Tj then shape Qk is considered as a shape generated from shape Si among
//!   shapes Q1, ..., Ql:
//!   Tj <= M12(Si), Qk <= G23(Tj) ==> Qk <= G13(Si);
//! 3) if shape Tj is modified from shape Si, shape Qk is modified from shape
//!   Tj then shape Qk is considered as a shape modified from shape Si among
//!   shapes Q1, ..., Ql:
//!   Tj <= M12(Si), Qk <= M23(Tj) ==> Qk <= M13(Si);
class BRepTools_History: public Standard_Transient
{
public:

  //! The types of the historical relations.
  enum TRelationType
  {
    TRelationType_Removed,
    TRelationType_Generated,
    TRelationType_Modified
  };

public:

  //! Returns 'true' if the type of the shape is supported by the history.
  static Standard_Boolean IsSupportedType(const TopoDS_Shape& theShape)
  {
    const TopAbs_ShapeEnum aType = theShape.ShapeType();
    return aType == TopAbs_VERTEX || aType == TopAbs_EDGE ||
      aType == TopAbs_FACE || aType == TopAbs_SOLID;
  }

public: //! Methods to set the history.

  //! Set the second shape as generated one from the first shape.
  Standard_EXPORT void AddGenerated(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated);

  //! Set the second shape as modified one from the first shape.
  Standard_EXPORT void AddModified(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified);

  //! Set the shape as removed one.
  Standard_EXPORT void Remove(const TopoDS_Shape& theRemoved);

  //! Set the second shape as the only generated one from the first one.
  Standard_EXPORT void ReplaceGenerated(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated);

  //! Set the second shape as the only modified one from the first one.
  Standard_EXPORT void ReplaceModified(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified);

  //! Clears the history.
  void Clear()
  {
    myShapeToModified.Clear();
    myShapeToGenerated.Clear();
    myRemoved.Clear();
  }

public: //! Methods to read the history.

  //! Returns all shapes generated from the shape.
  Standard_EXPORT
  const TopTools_ListOfShape& Generated(const TopoDS_Shape& theInitial) const;

  //! Returns all shapes modified from the shape.
  Standard_EXPORT
  const TopTools_ListOfShape& Modified(const TopoDS_Shape& theInitial) const;

  //! Returns 'true' if the shape is removed.
  Standard_EXPORT
  Standard_Boolean IsRemoved(const TopoDS_Shape& theInitial) const;

public: //! A method to merge a next history to this history.

  //! Merges the next history to this history.
  Standard_EXPORT void Merge(const Handle(BRepTools_History)& theHistory23);

public:

  //! Define the OCCT RTTI for the type.
  DEFINE_STANDARD_RTTIEXT(BRepTools_History, Standard_Transient)

private:
  //! Prepares the shapes generated from the first shape to set the second one
  //! as generated one from the first one by the addition or the replacement.
  //! Returns 'true' on success.
  Standard_Boolean prepareGenerated(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theGenerated);

  //! Prepares the shapes modified from the first shape to set the second one
  //! as modified one from the first one by the addition or the replacement.
  //! Returns 'true' on success.
  Standard_Boolean prepareModified(
    const TopoDS_Shape& theInitial, const TopoDS_Shape& theModified);

private: //! Data to keep the history.

  //! Maps each input shape to all shapes modified from it.
  //! If an input shape is not bound to the map then
  //! there is no shapes modified from the shape.
  //! No any shape should be mapped to an empty list.
  TopTools_DataMapOfShapeListOfShape myShapeToModified;

  //! Maps each input shape to all shapes generated from it.
  //! If an input shape is not bound to the map then
  //! there is no shapes generated from the shape.
  //! No any shape should be mapped to an empty list.
  TopTools_DataMapOfShapeListOfShape myShapeToGenerated;

  TopTools_MapOfShape myRemoved; //!< The removed shapes.

private: //! Auxiliary members to read the history.

  //! An auxiliary empty list.
  static const TopTools_ListOfShape myEmptyList;

  //! A method to export the auxiliary list.
  Standard_EXPORT static const TopTools_ListOfShape& emptyList();

private:

  //! Auxiliary messages.
  static const char* myMsgUnsupportedType;
  static const char* myMsgGeneratedAndRemoved;
  static const char* myMsgModifiedAndRemoved;
  static const char* myMsgGeneratedAndModified;
};

#endif // _BRepTools_History_HeaderFile
