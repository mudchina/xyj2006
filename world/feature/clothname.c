// clothname.c  

#include <ansi.h>

string *com_type = ({
"ñÄ°À"NOR, "¿íÉÀ"NOR, "Õ­ÉÀ"NOR, "º¹ÉÀ"NOR, "ÂÞÉÀ"NOR, "ÂÞ°À"NOR, "¶ÌÉÀ"NOR, 
"ÒÂÉÀ"NOR, "Ð¡¹Ó"NOR,
});
string *man_color = ({
CYN"Çà", BLU"À¶", WHT"°×", HIB"²ØÇà", GRN"ºúÂÌ", HIR"ç³ºì", 
BLK"Ôí", WHT"ËØ°×", HIM"×Ï", MAG"Ç³×Ï", 
});
string *com_material = ({
"²¼", "¾É", "Ó¡»¨", "³ñ", "Âé²¼", "´Ö²¼", 
});        
string *high_type = ({
"ÂÞÅÛ"NOR, "ÅÛ"NOR, "¿íÅÛ"NOR, "³¤ÉÀ"NOR, "ñÄ°À"NOR, "¿íÉÀ"NOR, "ÂÞÉÀ"NOR, 
"´óë©"NOR, "³¤ÅÛ"NOR,
});
string *high_material = ({
"¶Ð×Ó", "½õ", "³ñ", "±¡³ñ", "Ö±·ì", 
});                
string *wo_type = ({
"È¹"NOR, "ÂÞÈ¹"NOR, "ÉÀ"NOR, "½õ°À"NOR, "Ð¡°À"NOR, "³¤È¹"NOR, "ÂÞÒÂ"NOR,
});
string *wo_color = ({
RED"´óºì", RED"Òøºì", HIY"ÐÓ»Æ", GRN"´ÐÂÌ", BLU"À¶", MAG"ÅººÏÉ«"
, MAG"·Û", YEL"Äà½ð", WHT"ËØ°×", WHT"°×", GRN"ºúÂÌ", 
});
string *wo_material = ({
"³ñ", "Ï¸É´", "ÍÅ»¨", "Ðå»¨", "ÂÞ", "Áù·ù", "°Ùç§", "±¡³ñ", "¶Ô½ó", "ÎÆ½õ", 
});   
string *wos_type = ({
"Ð¬"NOR, "Ñ¥"NOR, "³¤Ñ¥"NOR, "Æ¤Ñ¥"NOR,
});
string *mans_type = ({
"Ñ¥"NOR, "³¤Ñ¥"NOR, "¿íÑ¥"NOR,"¿ìÑ¥"NOR,
});
string *wos_color = ({
RED"´óºì", RED"Òøºì", HIY"ÐÓ»Æ", GRN"´ÐÂÌ", BLU"À¶", MAG"ÅººÏÉ«"
, MAG"·Û", YEL"Äà½ð", WHT"ËØ°×", WHT"°×", GRN"ºúÂÌ", 
});
string *wos_material = ({
"³ñ", "Ï¸É´", "ÍÅ»¨", "Ðå»¨", "ÂÞ", "Áù·ù", "°Ùç§", "±¡³ñ", "Ë¿", "ÎÆ½õ", 
}); 
string *mans_color = ({
CYN"Çà", BLU"À¶", WHT"°×", HIB"²ØÇà", GRN"ºúÂÌ", HIR"ç³ºì", 
BLK"Ôí", WHT"ËØ°×", HIM"×Ï", MAG"Ç³×Ï", 
});
string *mans_material = ({
"±¡µ×", "½õ", "¸É»Æ", "ËÄ·ì", "Ö±·ì", 
});                                     
string comm_man_cloth()
{
    return man_color[ random ( sizeof ( man_color ) ) ] + com_material[ 
        random ( sizeof ( com_material ) ) ] + com_type[ random ( sizeof ( com_type ) ) ];
}
string high_man_cloth()
{
    return man_color[ random ( sizeof ( man_color ) ) ] + high_material[ random ( 
        sizeof ( high_material ) ) ] + high_type[ random ( sizeof ( high_type ) ) ];
}
string woman_cloth()
{
    return wo_color[ random ( sizeof ( wo_color ) ) ] + wo_material[ random ( sizeof ( 
        wo_material ) ) ] + wo_type[ random ( sizeof ( wo_type ) ) ];
}
string woman_shoes()
{
    return wos_color[ random ( sizeof ( wos_color ) ) ] + wos_material[ random ( sizeof ( 
        wos_material ) ) ] + wos_type[ random ( sizeof ( wos_type ) ) ];
}
string man_shoes()
{
    return mans_color[ random ( sizeof ( mans_color ) ) ] + mans_material[ random ( sizeof ( 
        mans_material ) ) ] + mans_type[ random ( sizeof ( mans_type ) ) ];
}



