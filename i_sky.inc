/*
  Persistence of Vision Ray Tracer Scene Description File

  Tierra v1.0 - Sky & Sun include, using Skylight

  --   
  Jaime Vives Piqueres, Apr-May-Jun 2004.

*/

// *** sky sphere and sun using CIE_Skylight and sunpos.inc ***
// random position
#ifndef(Al)    #declare Al=int(90*rand(r_sun)); #end
#ifndef(Az)    #declare Az=int(360*rand(r_sun)); #end
#ifndef(North) #declare North=<-1+2*rand(r_sun),0,-1+2*rand(r_sun)>; #end
#include "CIE_Skylight"
// ignore SunColor from Skylight, use blackbody model
#declare c_sun=Blackbody(2500+(4000*Al/90));
#declare DomeSize=1000;
light_source{ 
 SolarPosition, Light_Color(c_sun, 2*pi)
 parallel point_at 0
 looks_like{
  sphere{0,Sun_Size hollow
   texture{pigment{rgbt 1} finish{diffuse 0}}
   interior{media{emission Light_Color(c_sun,.001)}}
  }
 }
}

// fog
#switch (Haze_Tint)
 #case (0)
  #declare Haze_Color=SunColor;
  #break
 #case (1)
  #declare Haze_Color=c_sun;
  #break
 #case (2)
  #declare Haze_Color=HorizonColor;
  #break
#end
#declare Haze_Color=vnormalize(Haze_Color);
fog{
 fog_type 2
 color Haze_Color
 fog_offset 0.0001 //+Water_Height-Haze_Height
 fog_alt Haze_Height*.75
 distance (Haze_Distance/Current_Turbidity )
 turbulence .3 lambda 2.5
}

