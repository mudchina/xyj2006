// room: /d/qujing/baigudong/xiashanlu1 
//create by smile 12/09/1998
inherit ROOM;

void create ()
{
  set ("short", "下坡路");
  set ("long", @LONG

    四周静悄悄的，没有一点声音，空气似乎凝集不动了，
路旁有几棵野李子树(tree),不知道树上还有没有果实，
可以摇动看看有没有果子。
  
LONG);

  set("exits", ([
        "westdown"  : __DIR__"sanchakou",
        "eastup"    : __DIR__"xiapolu2",
      ]));

  set("outdoors",__DIR__"");

  setup();
}

void init()
{
 add_action("do_yao","yao");
 add_action("do_yao","push");
}

int do_yao(string arg)
{
  object me=this_player();
  object ob;
  object here=environment(me);
  int num=0;
  if(!arg) return notify_fail("你要摇什么?\n");
    if((arg!="tree")&&(arg!="树")&&(arg!="shu"))
       return notify_fail("你要摇什么?\n");
   if((num=me->query_temp("baigudong/guo"))>3) 
     {
      me->receive_damage("kee",20);
      return notify_fail("你使劲摇了摇树，没有果子掉下来。看来是没有果子了!\n");
     } 
    num+=1;
    me->set_temp("baigudong/guo",num);
    message_vision("你使劲摇了摇树，呀，掉下来一个野果。\n",me);
    me->receive_damage("kee",35);
   ob=new("/d/qujing/baigudong/obj/guo");
   ob->move(here);
  return 1;
}