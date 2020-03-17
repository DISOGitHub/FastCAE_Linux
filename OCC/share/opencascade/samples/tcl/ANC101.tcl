# The following example constructs ANC-101 object of CAM-I.
#
# This model was used as a test part for comparing modeling systems in 1979 and
# again in 1983. The tests were organized by Computer Aided Manufacturing
# International (CAM-I).
#
#Category: Modeling
#Title: ANC101 (classic test for CAD modeling from CAM-I)

pload MODELING

set my_pi 3.1415926535897931
set aModelHeight 178.25
set aPlatformLength 426.25
set aPlatformWidth 201.5
set aPlatformHeight 58.9
set aPrismLength 279
set aPrismWidth 155
set aPrismHeight [expr $aModelHeight - $aPlatformHeight]
set aPrismXOffset [expr $aPlatformLength - $aPrismLength - 69.75]
set aPrismYOffset [expr ($aPlatformWidth - $aPrismWidth)/2]

#================================================================================
# A base of the model
box _platform $aPlatformLength $aPlatformWidth $aPlatformHeight

# Make screw holes on the platform
set aScrewHoleRadius [expr 26.2/2]
set aScrewHoleOffset 31
pcylinder _screwhole $aScrewHoleRadius $aPlatformHeight
ttranslate _screwhole $aScrewHoleOffset $aScrewHoleOffset 0
bcut _platform _platform _screwhole
reset _screwhole
ttranslate _screwhole [expr $aPlatformLength - $aScrewHoleOffset] $aScrewHoleOffset 0
bcut _platform _platform _screwhole
reset _screwhole
ttranslate _screwhole [expr $aPlatformLength - $aScrewHoleOffset] [expr $aPlatformWidth - $aScrewHoleOffset] 0
bcut _platform _platform _screwhole
reset _screwhole
ttranslate _screwhole $aScrewHoleOffset [expr $aPlatformWidth - $aScrewHoleOffset] 0
bcut _platform _platform _screwhole
reset _screwhole

# Back side cave
set aCaveLength 81.38
set aCaveDepth 10
set aCaveWidth 19.38
set aBottomLevel [expr $aPlatformHeight/2 - $aCaveWidth/2]
set aTopLevel [expr $aPlatformHeight/2 + $aCaveWidth/2]
beziercurve t_bcurve 4  0 $aCaveLength $aBottomLevel  3  0 [expr $aCaveLength + $aCaveWidth/2] $aBottomLevel 6  0 [expr $aCaveLength + $aCaveWidth/2] $aTopLevel 6  0 $aCaveLength $aTopLevel 3
vertex t_v1 0 $aCaveLength $aBottomLevel
vertex t_v2 0 $aCaveLength $aTopLevel
mkedge t_e1 t_bcurve
edge t_e2 t_v1 t_v2
wire t_w t_e1 t_e2
mkplane t_f1 t_w
prism t_s1 t_f1 $aCaveDepth 0 0
box t_s2 0 0 $aBottomLevel $aCaveDepth $aCaveLength $aCaveWidth
bfuse _backcave t_s1 t_s2
bcut _platform _platform _backcave

# Right side cave
set aRCaveRadius 26.2
set aRCaveDistToSection 15.5
set aCurveParam [expr ($my_pi - acos($aRCaveDistToSection/$aRCaveRadius))]
set aRCaveCenterX [expr $aPlatformLength - 162.75]
set aRCaveCenterZ [expr $aPlatformHeight/2]
circle t_circle $aRCaveCenterX 0 $aRCaveCenterZ 0 1 0 1 0 0 $aRCaveRadius
trim t_curve t_circle -$aCurveParam $aCurveParam
mkedge t_e1 t_curve
cvalue t_curve -$aCurveParam t_x t_y t_z
vertex t_v1 t_x t_y t_z
cvalue t_curve $aCurveParam t_x t_y t_z
vertex t_v2 t_x t_y t_z
edge t_e2 t_v1 t_v2
wire t_w t_e1 t_e2
mkplane t_f t_w
prism t_s t_f 0 $aCaveDepth 0
bcut _platform _platform t_s

# Caves on front side
set aFCaveCirclesRadius 4.65
set aFCaveBottomWidth 37.8
set aFCaveHeight 38.75
set aFCaveTopWidth 27
set aFCaveSmallCircleRadius 9.3
circle t_circle1 [expr $aFCaveTopWidth/2] [expr $aFCaveHeight/2] $aFCaveCirclesRadius
circle t_circle2 [expr -$aFCaveTopWidth/2] [expr $aFCaveHeight/2] $aFCaveCirclesRadius
circle t_circle3 [expr -$aFCaveBottomWidth/2] [expr -$aFCaveHeight/2] $aFCaveCirclesRadius
circle t_circle4 [expr $aFCaveBottomWidth/2] [expr -$aFCaveHeight/2] $aFCaveCirclesRadius

lintan t_l t_circle1 t_circle2
trim t_side1 t_l_1 0 $aFCaveTopWidth

lintan t_l t_circle2 t_circle3
trim t_side2 t_l_1 0 39.058577803089555

lintan t_l t_circle3 t_circle4
trim t_side3 t_l_1 0 $aFCaveBottomWidth

lintan t_l t_circle4 t_circle1
trim t_side4 t_l_1 0 39.196587861700415

trim t_circle1 t_circle1 0.15109758878146562 1.5707963267948966 
trim t_circle2 t_circle2 1.5707963267948966 3.0158086349284448
trim t_circle3 t_circle3 3.0158086349284448 4.7123889803846897 
trim t_circle4 t_circle4 4.7123889803846897 0.15109758878146562 

plane t_plane 0 0 0 1 0 0 0 1 0

to3d t_circle1 t_circle1 t_plane
to3d t_circle2 t_circle2 t_plane
to3d t_circle3 t_circle3 t_plane
to3d t_circle4 t_circle4 t_plane
to3d t_side1 t_side1 t_plane
to3d t_side2 t_side2 t_plane
to3d t_side3 t_side3 t_plane
to3d t_side4 t_side4 t_plane

mkedge t_e1 t_circle1
mkedge t_e2 t_side1
mkedge t_e3 t_circle2
mkedge t_e4 t_side2
mkedge t_e5 t_circle3
mkedge t_e6 t_side3
mkedge t_e7 t_circle4
mkedge t_e8 t_side4

wire t_w t_e1 t_e2 t_e3 t_e4 t_e5 t_e6 t_e7 t_e8
mkplane t_f t_w
prism t_s1 t_f -$aCaveDepth 0 0

circle t_circle 0 [expr $aFCaveTopWidth/2 + $aFCaveBottomWidth/2] 0 1 0 0 $aFCaveSmallCircleRadius
mkedge t_e t_circle
wire t_w t_e
mkplane t_f t_w
prism t_s2 t_f [expr -$aCaveDepth/2] 0 0

box t_s3 0 0 -$aFCaveSmallCircleRadius  [expr -$aCaveDepth/2] [expr $aFCaveTopWidth/2 + $aFCaveBottomWidth/2] [expr $aFCaveSmallCircleRadius*2]

# Compile elements
bfuse t_s2 t_s2 t_s3
bfuse _frontcave t_s1 t_s2
unifysamedom _frontcave _frontcave

# Cut this cave from the platform
ttranslate _frontcave $aPlatformLength [expr $aPlatformWidth*2/3] [expr $aPlatformHeight/2]
bcut _platform _platform _frontcave

tmirror _frontcave $aPlatformLength [expr $aPlatformWidth/2] [expr $aPlatformHeight/2] 0 1 0
bcut _platform _platform _frontcave

#================================================================================
# A wedge on the platform
box t_box  $aPrismXOffset $aPrismYOffset $aPlatformHeight $aPrismLength $aPrismWidth $aPrismHeight

set aCutwedgeLength [expr $aPrismHeight/0.57735]
wedge _cutwedge $aPlatformLength [expr $aPrismYOffset + $aPrismWidth] $aModelHeight 0 -1 0 -1 0 0 $aCutwedgeLength $aPrismHeight $aPrismWidth 0

bcut _prism t_box _cutwedge

# Make 9 small holes on a top side
set aWedgeSmallHolesRadius 7.68
set aWedgeSmallHolesOrbit 67.81
set aWedgeHoleXPos [expr $aPrismXOffset + 77.5]
set aWedgeHoleYPos [expr $aPrismYOffset + 77.5]

plane t_plane $aWedgeHoleXPos $aWedgeHoleYPos [expr $aPlatformHeight + $aPrismHeight/2] 0 0 1 1 0 0
pcylinder t_cyl t_plane $aWedgeSmallHolesRadius [expr $aPrismHeight/2]

set i 2
while {$i <= 10} {ttranslate t_cyl [expr $aWedgeSmallHolesOrbit*cos($i*$my_pi/6)] [expr $aWedgeSmallHolesOrbit*sin($i*$my_pi/6)] 0; bcut _prism _prism t_cyl; reset t_cyl; incr i}

# Make a cylinder on a canted side
set aWedgeCylinderRadius 38.75
set aWedgeCylinderHeight 38.75
set aWedgeCantedHeight [expr tan($my_pi/6)*($aCutwedgeLength - 69.75)]
set aWedgeCylinderZPos [expr $aModelHeight - $aWedgeCantedHeight/2]
plane t_plane [expr $aPrismXOffset + $aPrismLength*3/4] [expr $aPrismYOffset + $aPrismWidth/2] $aWedgeCylinderZPos cos($my_pi/3) 0 sin($my_pi/3) 0 1 0
pcylinder t_cyl t_plane $aWedgeCylinderRadius $aWedgeCylinderHeight
explode t_cyl e
blend t_cyl t_cyl 3 t_cyl_1
bfuse _prism _prism t_cyl
unifysamedom _prism _prism

# Make a hole in the cylinder on the wedge
pcylinder t_cyl t_plane [expr $aWedgeCylinderRadius/2] 100
ttranslate t_cyl [expr -60*cos($my_pi/3)] 0 [expr -60*sin($my_pi/3)]
bcut _prism _prism t_cyl

# Make a hole on a right side of the wedge
plane t_plane [expr $aPlatformLength - 162.75] $aPrismYOffset [expr $aModelHeight - $aWedgeCantedHeight] 0 1 0 1 0 0
pcylinder t_cyl t_plane 13.1 [expr $aPrismWidth/2]
bcut _prism _prism t_cyl

# Fuse the platform and the prism
bfuse _model _platform _prism

# Make a pass-through hole
set aWedgeHoleInnerRadius 38.77
set aWedgeHoleOuterRadius 58.13
set aWedgeHoleBottomInnerRadius 50.38

# Cylinders from bottom to top
plane t_plane $aWedgeHoleXPos $aWedgeHoleYPos 0
pcylinder t_cyl1 t_plane $aWedgeHoleOuterRadius 10
pcylinder t_cyl2 t_plane $aWedgeHoleBottomInnerRadius 10
pcylinder t_cyl3 t_plane $aWedgeHoleInnerRadius [expr $aModelHeight - 30]
pcylinder t_cyl4 t_plane $aWedgeHoleOuterRadius 10

ttranslate t_cyl2 0 0 10
ttranslate t_cyl3 0 0 20
ttranslate t_cyl4 0 0 [expr $aModelHeight - 10]

bfuse _cutCylindricShape t_cyl1 t_cyl2
bfuse _cutCylindricShape _cutCylindricShape t_cyl3
bfuse _cutCylindricShape _cutCylindricShape t_cyl4

bcut _model _model _cutCylindricShape

# Add a block on left side
circle t_circle1 0 0 38.75
circle t_circle2 [expr 38.75 + 9.3] [expr -57.35 + 9.3] 9.3
circle t_circle3 [expr -38.75 - 9.3] [expr -57.35 + 9.3] 9.3

lintan t_l t_circle1 t_circle2
trim t_line12 t_l_2 0 48.05

lintan t_l t_circle2 t_circle3
trim t_line23 t_l_3 0 96.1

lintan t_l t_circle3 t_circle1
trim t_line31 t_l_4 0 48.05

trim t_circle1 t_circle1 0 $my_pi
trim t_circle2 t_circle2 $my_pi 4.7123889803846897
trim t_circle3 t_circle3 4.7123889803846897 6.2831853071795862

reverse t_circle1

plane t_plane [expr $aPrismXOffset + 77.5] [expr $aPrismYOffset + $aPrismWidth] [expr $aPlatformHeight + 57.35] 0 1 0 -1 0 0

to3d t_circle1 t_circle1 t_plane
to3d t_circle2 t_circle2 t_plane
to3d t_circle3 t_circle3 t_plane
to3d t_line12 t_line12 t_plane
to3d t_line23 t_line23 t_plane
to3d t_line31 t_line31 t_plane

mkedge t_e1 t_circle1
mkedge t_e2 t_line31
mkedge t_e3 t_circle3
mkedge t_e4 t_line23
mkedge t_e5 t_circle2
mkedge t_e6 t_line12

wire t_w t_e1 t_e2 t_e3 t_e4 t_e5 t_e6
mkplane t_f t_w
prism t_s t_f 0 $aCaveDepth 0

bfuse _model _model t_s

# Make fillets
explode _model e

# Make a weld at joint edges of platform and wedge 
blend _model _model 2 _model_26
blend _model _model 2 _model_27
blend _model _model 2 _model_28
blend _model _model 2 _model_29
blend _model _model 2 _model_31

# Cylinder on wedge
blend result _model 2 _model_161

# Show result
pload VISUALIZATION
vinit Driver1/Viewer1/View1
vsetcolorbg 200 200 255
vdisplay result
vfit
vsetdispmode 1
vshowfaceboundary result 1
