//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Materials list
//==================================================
//This file has been created by PoseRay v3.13.31.705
//3D model to POV-Ray/Moray Converter.
//Author: FlyerX
//Email: flyerx_2000@yahoo.com
//Web: https://sites.google.com/site/poseray/
//==================================================
//Files needed to run the POV-Ray scene:
//seagul_POV_main.ini (initialization file - open this to render)
//seagul_POV_scene.pov (scene setup of cameras, lights and geometry)
//seagul_POV_geom.in (geometry)
//seagul_POV_mat.inc (materials)
//texture001.jpg
//texture002.jpg
//texture000.jpg
// 
 
//Macros used by PoseRay to manipulate pigments
//Nov 07, 2017
//By FlyerX 

#macro pigment_fade2(p1,f)
//filters a pigment by a value f. f=0 pigment is white, f=1 pigment is p1
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {(PR1(x,y,z).red-1)*f+1}
#local PR_FGrn=function (x,y,z) {(PR1(x,y,z).green-1)*f+1}
#local PR_FBlu=function (x,y,z) {(PR1(x,y,z).blue-1)*f+1}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

#macro pigment_gray2(p1)
//converts to grayscale using luminance
#local PR1 = function {pigment{p1}}
#local PR_Gray=function (x,y,z) {0.2126*PR1(x,y,z).red+0.7152*PR1(x,y,z).green+0.0722*PR1(x,y,z).blue}
function{PR_Gray(x,y,z)}
#end  

#macro pigment_multiply2(p1,p2)
//multiplies two pigments p1xp2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*PR2(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*PR2(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*PR2(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_screen2(p1,p2)
//screens two pigments p1 p2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {1-(1-PR1(x,y,z).red)*(1-PR2(x,y,z).red)}
#local PR_FGrn=function (x,y,z) {1-(1-PR1(x,y,z).green)*(1-PR2(x,y,z).green)}
#local PR_FBlu=function (x,y,z) {1-(1-PR1(x,y,z).blue)*(1-PR2(x,y,z).blue)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end        

#macro pigment_divide2(p1,p2)
//divides pigment p2 by p1
//1/256 is added to the dividing color to prevent division by zero 
//colors are clipped to 0-1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red/(PR1(x,y,z).red+0.004),0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green/(PR1(x,y,z).green+0.004),0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue/(PR1(x,y,z).blue+0.004),0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end  


#macro pigment_add2(p1,p2)
//adds two pigments - values are clipped 0 to 1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR1(x,y,z).red+PR2(x,y,z).red,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR1(x,y,z).green+PR2(x,y,z).green,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR1(x,y,z).blue+PR2(x,y,z).blue,0,1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

#macro pigment_substract2(p1,p2)
//subtracts two pigments - values are clipped 0 to 1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red-PR1(x,y,z).red,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green-PR1(x,y,z).green,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue-PR1(x,y,z).blue,0,1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end

#macro pigment_colorburn2(p1,p2)
//burns p1 onto p2
//if image maps, they should be set to gamma 1 or it will give wrong results. 
//resulting image should be gamma corrected again using pigment_power(pigment,2.2)
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(1-((1-PR2(x,y,z).red)/(PR1(x,y,z).red+0.004)),0,1)}
#local PR_FGrn=function (x,y,z) {clip(1-((1-PR2(x,y,z).green)/(PR1(x,y,z).green+0.004)),0,1)}
#local PR_FBlu=function (x,y,z) {clip(1-((1-PR2(x,y,z).blue)/(PR1(x,y,z).blue+0.004)),0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_linearburn2(p1,p2)
//burns p1 onto p2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red+PR1(x,y,z).red-1,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green+PR1(x,y,z).green-1,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue+PR1(x,y,z).blue-1,0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_overlay2(p1,p2)
//overlays p1 onto p2
//if image maps, they should be set to gamma 1 or it will give wrong results. 
//resulting image should be gamma corrected again using pigment_power(pigment,2.2)
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}


#local PR_FRed=function (x,y,z) {select((PR2(x,y,z).red-0.5),
clip(2*PR1(x,y,z).red*PR2(x,y,z).red,0,1),
clip(1-2*(1-PR1(x,y,z).red)*(1-PR2(x,y,z).red),0,1))}

#local PR_FGrn=function (x,y,z) {select((PR2(x,y,z).green-0.5),
clip(2*PR1(x,y,z).green*PR2(x,y,z).green,0,1),
clip(1-2*(1-PR1(x,y,z).green)*(1-PR2(x,y,z).green),0,1))}

#local PR_FBlu=function (x,y,z) {select((PR2(x,y,z).blue-0.5),
clip(2*PR1(x,y,z).blue*PR2(x,y,z).blue,0,1),
clip(1-2*(1-PR1(x,y,z).blue)*(1-PR2(x,y,z).blue),0,1))}

average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_transmit2(p1,tr)
//sets the transparency of p1 to tr
#local PR1 = function {pigment{p1}} 
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <1,0,0,0,tr/3>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,1,0,0,tr/3>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,0,1,0,tr/3>*3]}]   
  }
#end  

#macro pigment_process2(p1,p2,tr)
//multiplies two pigments and sets the transparency to tr
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*PR2(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*PR2(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*PR2(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <1,0,0,0,tr/3>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,1,0,0,tr/3>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,0,1,0,tr/3>*3]}]    
  }
#end   



#macro pigment_power2(p1,n)
//raises a pigment to a power - works with images with no mask (jpeg, bmp...)
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {pow(PR1(x,y,z).red,n)}
#local PR_FGrn=function (x,y,z) {pow(PR1(x,y,z).green,n)}
#local PR_FBlu=function (x,y,z) {pow(PR1(x,y,z).blue,n)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 


#macro pigment_threshold2(p1,s)
//makes a pigment black if color < s or white otherwise
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {0.5*(sgn(PR1(x,y,z).red-s)+1)}
#local PR_FGrn=function (x,y,z) {0.5*(sgn(PR1(x,y,z).green-s)+1)}
#local PR_FBlu=function (x,y,z) {0.5*(sgn(PR1(x,y,z).blue-s)+1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end  


#macro pigment_invert2(p1)
//inverts the color -> 1-RGB
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {1-PR1(x,y,z).red}
#local PR_FGrn=function (x,y,z) {1-PR1(x,y,z).green}
#local PR_FBlu=function (x,y,z) {1-PR1(x,y,z).blue}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

 

#macro pigment_mix2(p1,p2,xv)
//mixes two pigments on a sliding scale xv from 0 to 1 
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*(1-xv)+PR2(x,y,z).red*xv}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*(1-xv)+PR2(x,y,z).green*xv}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*(1-xv)+PR2(x,y,z).blue*xv}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end

#macro color_adjustHSV2(c,h,s,v2)
#local hc=CRGB2HSV(c);
#local hc2=<hc.red*h,hc.green*s,hc.blue*v2,(hc.filter),(hc.transmit)>;
#local c2=CHSV2RGB(<hc.red*h,hc.green*s,hc.blue*v2>);  
<c2.x,c2.y,c2.z>
#end 



#macro color_adjustHSVR2(c,h,s,v2)
color_adjustHSVR(c,h,s,v2).red
#end


#macro pigment_adjustHSV2(p1,h,s,v2)
//
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {color_adjustHSVR(<1,2,3>,1,1,1)}
#local PR_FGrn=function (x,y,z) {color_adjustHSV(<PR1(x,y,z).red,PR1(x,y,z).green,PR1(x,y,z).blue>,1,1,1).green}
#local PR_FBlu=function (x,y,z) {color_adjustHSV(<PR1(x,y,z).red,PR1(x,y,z).green,PR1(x,y,z).blue>,1,1,1).blue}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro color_adjust_lum2(c1,Lum2)
//change color luminosity in c1 to Lum2
//h2l must be between 0 and 1
#local h1=CRGB2HSL(c1);
#local h2=<h1.red,h1.green,Lum2>;
#local c2=CHSL2RGB(h2);  
<c2.x,c2.y,c2.z>
#end





#macro pigment_adjust_lum2(p1,lum)
//changes the luminosity of a pigment
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {color_adjust_lum(<PR1(x,y,z).red,PR1(x,y,z).green,PR1(x,y,z).blue>,lum).red}
#local PR_FGrn=function (x,y,z) {color_adjust_lum(<PR1(x,y,z).red,PR1(x,y,z).green,PR1(x,y,z).blue>,lum).green}
#local PR_FBlu=function (x,y,z) {color_adjust_lum(<PR1(x,y,z).red,PR1(x,y,z).green,PR1(x,y,z).blue>,lum).blue}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

//=======================================

#macro power_ramp(xv,xa,xb,ya,yb,pw)
//generates a float with a power ramp from (xa,ya) to (xb,yb) with power pw and argument xv. 
//ramp slope is zero at xb
#local xx=clip(xv,xa,xb);
  ((ya-yb)/pow((xa-xb),pw))*pow((xx-xb),pw)+yb
#end

#macro power_ramp2(xv,xa,xb,ya,yb,pw)
//generates a float with a power ramp from (xa,ya) to (xb,yb) with power pw and argument xv. 
//ramp slope is zero at xa
#local xx=clip(xv,xa,xb);
  ((yb-ya)/pow((xb-xa),pw))*pow((xx-xa),pw)+ya
#end

#macro linear_ramp(xv,xa,xb,ya,yb)
//generates a linear float from (xa,ya) to (xb,yb)
  (yb-ya)/(xb-xa)*(xv-xa)+ya
#end

#declare smootherstep2=function(x){ x*x*x*(x*(x*6-15)+10) }

#macro smoothramp(xv,xa,xb,ya,yb)
//smooth ramp similar to power ramps above
//slope is zero at both ends
#local xx=clip((xv-xa)/(xb-xa),0,1);
ya+smootherstep2(xx)*(yb-ya)
#end

#macro cosineramp(xv,xa,xb,ya,yb)
//smooth ramp similar to power ramps above
//slope is zero at both ends
#local xx=clip(xv,xa,xb);
Interpolate(xx,xa,xb,ya,yb,0)
#end
 
//==================================================
//Map definitions
#declare p_map1=pigment {image_map{jpeg "./Objects/bird/texture001.jpg"   transmit all 0 } }
#declare p_map2=pigment {image_map{jpeg "./Objects/bird/texture002.jpg"   transmit all 0 } }
#declare p_map3=pigment {image_map{jpeg "./Objects/bird/texture000.jpg"   transmit all 0 } }
 
//==================================================
//Material definitions
#declare mat_0_texture001_jpg_=
#declare PR_DIFFUSE=pigment{p_map1}


#declare F1=finish{specular  0 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare mat_1_texture002_jpg_=
#declare PR_DIFFUSE=pigment{p_map2}


#declare F1=finish{specular  0 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare mat_2_texture002_jpg_=
#declare PR_DIFFUSE=pigment{p_map2}


#declare F1=finish{specular  0 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare mat_3_texture001_jpg_=
#declare PR_DIFFUSE=pigment{p_map1}


#declare F1=finish{specular  0 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare mat_4_texture000_jpg_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
 
//restore the version used outside this file
#version Temp_version;
//==================================================
