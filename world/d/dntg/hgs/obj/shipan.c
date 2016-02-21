
inherit ITEM;

void create()
{
	int i;
        object a;

        set_name("石盘", ({ "shi pan" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
          {
          seteuid(getuid());
	  for (i=1;i<=10;i++) 	
            {
            a=new("/d/obj/drug/mihoutao");
            a->move(this_object());
            }
          set_default_object(__FILE__);
          }
        else 
          {
          set("unit", "个");
          set("long", "一个石盘子。\n");
          set("no_give", 1);
          }
}

int is_container() { return 1; }

