inherit ROOM;

void create ()
{
        set ("short", "长安照相馆");
        set ("long", @LONG

这里是这个世界里最前卫的地方了。
墙壁四周挂满了人们的照片，形态各异。
摄影师坐在旁边，招呼着客人。
但是他好象现在已经不为人照相了,只是把相机借给
别人。
LONG);
      set("exits", ([ /* sizeof() == 1 */
      "southeast" : __DIR__"home",
           "east" : __DIR__"zxg-1",
]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/sheyingshi" : 1]));
  set("no_clean_up", 0);
  set("no_fight", 1);
  set("no_magic", 1);



        setup();
}


void init() {
  add_action("do_borrow",({"borrow","jie"}));
}

int do_borrow(string arg) {

   object camera,me=this_player();
   camera=new("/obj/toy/camera");
   camera->move(this_player());
   message_vision("火麒麟给$N一部照相机。\n",me);
   return 1;
}         

int valid_leave (object camera, string dir)
{
   camera=this_object();

        if (camera=present("camera",this_player()) && dir == "southeast") {
        return notify_fail("你不能把照相机带走！\n");
        tell_object(this_player(),"你将相机交回给火麒麟。\n");
//        destruct(camera);
        this_player()->move("/u/rico/home");
        }
    return ::valid_leave();

}
