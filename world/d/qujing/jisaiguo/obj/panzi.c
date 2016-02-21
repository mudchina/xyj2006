inherit ITEM;

void create()
{
        set_name("玻璃盘子", ({ "panzi" }) );
        set_weight(500);
        set_max_encumbrance(500);
        set_max_items(2);
        if( clonep() ){
		object a,b;
		if(random(2) > 0 ) {
                seteuid(getuid());
                if(a=new("/d/obj/drug/xiandan"))
                  a->move(this_object());
		seteuid(getuid());
		if(b=new("/d/obj/drug/fake-xiandan")) 
                  b->move(this_object());
		} else {
		seteuid(getuid());
                if(a=new("/d/obj/drug/fake-xiandan"))
                  a->move(this_object());
                seteuid(getuid());
                if(b=new("/d/obj/drug/xiandan"))
                  b->move(this_object());
		} 
                set_default_object(__FILE__);
      }  else {
                set("unit", "个");
                set("long", "这是一口玻璃盘子。\n");
		set("value", 0);
        }
}

int is_container() { return 1; }


