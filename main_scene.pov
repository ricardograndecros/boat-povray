// POV-Ray 3.7 Scene File "main_scene.pov"
// author: Ricardo Grande Cros
// Date:   May 2022
//-------------------------------------------------------------------------- 
#version 3.7;
#if (version < 3.7) global_settings{ assumed_gamma 1.0 } #end
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"

// sun ---------------------------------------------------------------------
    
// ground ------------------------------------------------------------------
// the dimensions of the hole:
#declare HoleInnerR = 2;
#declare HoleScale  = 1.50;
#declare HoleR      = 2.2;
//-------------------------

// *************************
// *** standard includes ***
// *************************
#include "colors.inc"
#include "textures.inc"
#include "functions.inc"


// *******************************
// *** CIE & LIGHTSYS includes ***
// *******************************
#include "CIE.inc"
#include "lightsys.inc"          
#declare Lightsys_Brightness=1;
// change white point to typical outdoor white balance
CIE_ColorSystemWhitepoint(sRGB_ColSys,Daylight2Whitepoint(5500))


// ***************
// *** globals ***
// ***************
#declare Landscape_Size=500; // side of the seascape square 
#declare r_sun   = seed(8124); // seed for random sun placement
#declare r_water = seed(8034); // water surface seed


// ****************************
// *** sun & sky parameters ***
// ****************************
// skylight params:
#declare Current_Turbidity=3; // skylight turbidity (influences haze)
#declare Intensity_Mult =.75; // skylight intensity
#declare Max_Vertices  =1000; // skylight mesh resolution
#declare Sun_Size      =5000; // aparent size of the sun
// sun placement settings (uses rand seed if these are not specified)
//#declare Az   =120;
//#declare Al   = 50;
//#declare North=-z;
// haze params:
#declare use_atmosphere=1; // use haze?
#declare Haze_Height   =1; // full height 
#declare Haze_Distance=40; // turbidity also affects distance
#declare Haze_Tint     =2; // 0=Sky color, 1=Sun color, 2=Horizon color
#declare use_ambient   =0; // fill lihts


// ************************
// *** water parameters ***
// ************************
#declare Water_Height =1;  // water level
#declare Water_Surface=1;  // 1=isosurface, 2=plane with normal


// call the includes
#include "i_sky.inc"
#include "i_water.inc"        

     

//PoseRay default Light attached to the camera
light_source {
              <0,(Water_Height+3),-Landscape_Size*.49+2> //light position
              color rgb <1,1,1>*1.6
              parallel
              point_at <0,0,0>
             }



 
 
//torus spiral normal
#declare torus_normal =  normal {spiral1  10  0.5  sine_wave    
                 turbulence 0.2 rotate<90,0,0> scale <0.25,1,0.25> }

#declare water_normal = normal {function{f_water(x,0,y)} rotate 90*x}         
// the plane with a hole:
union{ 
difference{

object{water} 
/*plane { <0,1,0>, 0  hollow // normal vector, distance to zero ----
       translate<0,1,0>
       texture {pigment {color Blue}}
       
      }*/ // end of plane ------------------------------------------


cylinder{<0,-HoleR,0>, <0,Water_Height + 0.1,0>,HoleInnerR+HoleR scale HoleScale}
cylinder{<0,  -100,0>, <0,Water_Height + 0.1,0>,HoleInnerR scale HoleScale}
          } // end of difference
          
torus{ HoleInnerR+HoleR, HoleR 
       translate<0,-HoleR+0.75 ,0>scale HoleScale
       material {texture{ pigment{wc}
  normal {
   gradient y
   normal_map{
        [0 torus_normal ]
        [0.98 water_normal]  
   }                         
   scale HoleScale
  
  }
  finish { // borrowed from Christof Hormann
      diffuse 0
      ambient 0
      reflection {
        0.0, 1.0
        fresnel on
      }
      conserve_energy
      specular 0.4
      roughness 0.0035}}
  
  //material{m_water}
 
 
 }
 interior{i_water}
 }

    
 
 translate<0,0,-Landscape_Size*.49+10>
 } // end of union

//-----------------------------------------------------------------------                      
// **************
// ***  BOAT  ***
// **************
global_settings{
 //max_trace_level 3 
 assumed_gamma 1.0 
}
#include "Boat_POV_geom.inc" //Geometry           
//Assembled object that is contained in Boat_POV_geom.inc with no SSLT components
//Assembled object that is contained in Boat_POV_geom.inc with no SSLT components
object{
      Boat_                 
      scale<0.1,0.1,0.1>
      translate <450,-35,80>
      scale<0.5,0.5,0.5>
      rotate <-1,101,-15>
      }          


//-------------------------------------------------------------------------- 
// **************
// *** SEAGUL ***
// **************
#include "seagul_POV_geom.inc" //Geometry
union {object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-13,8,-90>
      translate <5,6,-Landscape_Size*.49+20>
      }

object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <10,4,-90>
      translate <5,9,-Landscape_Size*.49+22>
      }
      
 
 object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <8,-6,-90>
      translate <2,7,-Landscape_Size*.49+23>
      }
      
 
 object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <7,0,-90>
      translate <4,6,-Landscape_Size*.49+28>
      }  
      
  object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-16,0,-90>
      translate <2,8,-Landscape_Size*.49+15>
      }
  
   object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <0,0,-90>
      translate <6,7,-Landscape_Size*.49+18>
      }
      
   object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-8,0,-90>
      translate <5,4,-Landscape_Size*.49+21>
      }
      
  object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <4,8,-90>
      translate <5,7,-Landscape_Size*.49+26>
      }
      
  object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <22,7.2,-90>
      translate <6,6.5,-Landscape_Size*.49+20>
      }
      
   object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <8,4.6,-90>
      translate <4,4.5,-Landscape_Size*.49+24>
      }
      
      
    object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-6,5,-90>
      translate <5.7,8.6,-Landscape_Size*.49+16>
      }
      
     object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-7,5,-90>
      translate <0,6.7,-Landscape_Size*.49+23.7>
      }
      
     object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-4,5,-90>
      translate <-2,9.1,-Landscape_Size*.49+18.7>
      }
      
    object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-8,5,-90>
      translate <3,8.6,-Landscape_Size*.49+20.8>
      }
      
    object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-6,5,-90>
      translate <4.6,10.5,-Landscape_Size*.49+16.8>
      }
      
    object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-7,5,-90>
      translate <3.8,7.8,-Landscape_Size*.49+18>
      }
      
    object{
      UVGFV42R0TSS05RUGB1OAX98A_
      rotate <-10,5,-90>
      translate <4.2,6,-Landscape_Size*.49+12>
      }
      translate<-3,0,0>
      }


// **************
// *** camera ***
// **************
#declare camera0 = camera{ 
 location <0,(Water_Height),-Landscape_Size*.49>
 up 0.000024*y right 0.000032*x
 direction .000050*z
 look_at <0,-5,0>
 //rotate -30*y
}               


#declare camera1 = camera{ 
 location <0,(Water_Height+6),-Landscape_Size*.49-25>
 up 0.000024*y right 0.000032*x
 direction .000050*z
 look_at <0,-10,0>
} 


camera {camera1}  