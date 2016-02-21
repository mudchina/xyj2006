// bishuizhou.c

inherit ITEM;

void create()
{
        set_name("避水咒", ({"bishui zhou","zhou"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
	set("long",
	"一张小纸片。上面写着“避水咒”三个字，不知道有什么用没有。\n");
        set("material", "paper");       
        }
}


