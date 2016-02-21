// paper_seal.c

inherit ITEM;

void create()
{
	set_name("桃符纸", ({"paper seal", "seal", "paper"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long","这是张用来画符的符纸，具有封存法力的功用。\n");
	set("unit", "叠");
	set("value", 10);
	}
	setup();
}

