inherit ITEM;

void create()
{
        set_name("兵器架", ({ "rack" }) );
        set_weight(5000000);
        set_max_encumbrance(40001);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/d/obj/weapon/fork/gangcha"))
                  a->move(this_object());

                  seteuid(getuid());
                if(d=new("/d/obj/weapon/fork/gangcha"))
                  d->move(this_object());

                  seteuid(getuid());
                if(b=new("/d/obj/armor/tenjia"))
                  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/d/obj/armor/tenjia"))
                  e->move(this_object());

                  seteuid(getuid());
                if(c=new("/d/obj/weapon/fork/gangcha"))
                  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long",
"这是一口寻常的架子，可以用来堆放一些杂物。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }


