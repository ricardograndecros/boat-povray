/*
  Persistence of Vision Ray Tracer Scene Description File

  Isosurface Water include

  --   
  Jaime Vives Piqueres, Nov 2006.

*/

// water surface functions
#declare f_water_waves1=
function{
 pattern{
  pigment_pattern{
   granite scale 4
   turbulence .1
   poly_wave .5
   color_map{[0 rgb 0][1 rgb -1]}
   scale 2
  }
 }
}
#declare f_water_waves2=
function{
 pattern{
  pigment_pattern{
   ripples
   turbulence .33
   color_map{[0 rgb 0][1 rgb 1]}
   scale 1
   rotate 360*rand(r_water)
  }
 }
}
#declare f_water=
function{
 f_water_waves1(x,0,z)*f_water_waves1(x,1,z)
}


// *** water material ***
#declare wc=rgb MediumAquamarine; // water color
#declare t_water=
texture{
  pigment{rgbt 1}
  #if (Water_Surface=2) // normal only for tests
  normal{function{f_water(x,0,y)} rotate 90*x}
  #end
  finish { // borrowed from Christof Hormann
      diffuse 0
      ambient 0
      reflection {
        0.0, 1.0
        fresnel on
      }
      conserve_energy
      specular 0.4
      roughness 0.0035
  }
}
#declare i_water=
interior{
 ior 1.33 
 fade_power 1000
 fade_distance .001
 fade_color wc
 media{absorption 1}
}
#declare m_water=
material{
 texture{t_water} interior{i_water}
}


// *** water object ***
#if (Water_Surface=2)

 // test plane
 #declare water_aux=
 plane{y, 0

#else

 // isosurface water
 #declare kw=4;
 #declare water_aux=
 isosurface{
  function{ 
   y
   -f_water(x,0,z)*.05*kw-f_water(x*.5,0,z*.5)*.1*kw-f_water(x*2,0,z*2)*.025*kw-f_water(x*4,0,z*4)*.0125*kw
  }
  max_gradient 1
  contained_by{box{<-Landscape_Size*.5,-Water_Height,-Landscape_Size*.5>,<Landscape_Size*.5,.2*kw,Landscape_Size*.5>}}

#end
 
 material{m_water}
}
//object{water_aux hollow translate Water_Height*y} 

// *** underwater plane to reinforce effect ***
#declare bottom_plane = plane{y,0
 pigment{
  wc
 }
}

#declare water = union {object{water_aux hollow translate Water_Height*y}
                         plane{y,0
                         pigment{
                          wc
                         }
                        }
}

//object{water} 



