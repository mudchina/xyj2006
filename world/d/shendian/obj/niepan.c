
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("·ï»ËÄùÅÍ", ({"niepan", "pan"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long",HIR"Ò»¸öÎåÉ«µÄÔ²ÅÌ¡£ÉÏÃæ¿Ì×Å½ğÄ¾Ë®»ğÍÁÎåÖÖ·ûºÅ¡NNOR£");
                set("base_unit", "¸ö");
                set("base_weight", 0);
                set("no_sell","ÕâÃ´Õä¹óµÄ¶«Î÷ÕâÀï¿É²»¸ÒÊÕ£¡" );
                set("no_get","Õâ¸ö¶«Î÷¼ğ²»ÆğÀ´");
                set("no_give","ÕâÃ´Õä¹óµÄ¶«Î÷¸ø±ğÈË²»´óºÃ°É"); 
        }
         setup();
}

