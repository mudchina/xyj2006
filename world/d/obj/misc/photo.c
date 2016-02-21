// ash.c

inherit ITEM;

void create()
{
        set_name("灰烬", ({ "huijin", "ash" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                                set("unit", "张");
                                set("value",0);
                set("long", "一堆无法辨认的焦黑的灰烬，象是一场浩劫后留下的残余。\n");
                }
        setup();
}

void init()
{
   add_action("do_sign","sign");
}

int do_sign(string arg) {
   object me=this_player();
   string str;

   if (arg!="photo") return 0;
   if (query("name")!=me->query("name")+"的照片")
        return notify_fail("禁止在别人的照片上乱涂乱画！\n");

   str=query("long");
   str=str+ "照片上有"+me->query("name")+"的亲笔签名。\n";
   
   message_vision("$N在照片上龙飞凤舞的签上了自己的大名。\n",me);
   set("long",str);
   set("name",me->query("name")+"的签名照片");
   remove_action("do_sign","sign");
   return 1;
}
   

