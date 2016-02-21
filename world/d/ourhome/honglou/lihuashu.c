
inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "梨花树下");
  set ("long", @LONG

     梨花院落溶溶月，柳絮池塘淡淡风。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yard2",
]));
  setup();
}
void init() {
  add_action("do_dig",({"dig","wa","jue"}));
}

int do_dig(string arg) {

  object wan,me=this_player();

  if (!arg && arg!="tree" && arg!="lihua tree")
    return notify_fail("你要挖什么？\n");
  
  if (me->is_busy()) return notify_fail("休息一会儿再挖吧。\n");

  me->add("kee",-50);
  message_vision("$N在梨花树下挖了半天，累得满头大汗。\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N挖出一个细磁药坛，却发现里面空空如也。\n",me);
      else {
         message_vision("$N挖出一个细磁药坛，从里面拿出了一粒药丸。\n",me);
         wan=new("/d/obj/drug/lengxiangwan");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(3+random(3));
  return 1;
}         
    
        
