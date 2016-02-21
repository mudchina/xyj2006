//Cracked by Roath

inherit ITEM;

void create()
{
        set_name("[33m¹¦µÂÏä[m", ({ "xiang","box" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Ú");
                set("no_get",1);
                set("long", "ÕâÊÇÒ»¿Ú½ÓÊÜÄ¼¾èµÄÏä×Ó¡£\n");
                set("value",900);
        }
}

int is_container() { return 1; }
