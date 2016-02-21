inherit ITEM;

void create()
{
        set_name("定海神针", ({ "shenzhen" }));
	set_weight(100000);
	if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "传说中的定海神针。但仔细看去，又似乎有些不对头，让人不觉感到一些怀疑。\n");
		set("unit", "根");
set("value", 1000);
		set("material", "iron");
		}
	setup();
}



