
inherit ITEM;

void create()
{
	int i;

        set_name("月饼盒", ({ "cookie box","box" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
          {
          seteuid(getuid());
          set_default_object(__FILE__);
          }
        else 
          {
          set("unit", "个");
          set("long", "一盒由西游记2006西安站巫师组制作的月饼，祝您中秋快乐！\n");
          set("no_give", 1);
          }
}

int is_container() { return 1; }

