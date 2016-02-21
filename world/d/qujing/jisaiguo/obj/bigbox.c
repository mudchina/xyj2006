inherit ITEM;

void create()
{
        set_name("粗木箱子", ({ "big box", "box"}));
        set_weight(40000);
        if( clonep() ) {
                set("unit", "个");
                set("long","一个装货的粗木箱子，看起来相当沉重。\n");
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        if( environment() != environment(this_player())
        ||      !id(arg) ) return 0;

        if( (int)this_player()->query_stat("kee") < 10 ) {
                write("你的力气不够了，歇歇再搬吧！\n");
                return 1;
        }

        if( move(this_player()) ) {
                message_vision("$N弯腰将地下的" + name()+"扛了起来。\n", 
this_player());
                this_player()->consume_stat("kee", 10);
                return 1;
        }
}

