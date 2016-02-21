//Cracked by Roath

inherit ITEM;
void create()
{
        set_name("状纸", ({"zhuang zhi", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张状纸，上面密密麻麻的写了一些东西．\n");
                set("material", "paper");
        }
}
