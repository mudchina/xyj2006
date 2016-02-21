void init() {
   add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object *bulb;
  object me=this_player();
  string dest;
 
  if( (!arg) || arg != "tree" )
    return notify_fail("爬什么？\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("kee")/2);
    return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
  }

  bulb=all_inventory();
  for (int i=0;i<sizeof(bulb);i++) 
     if (living(bulb[i]) && bulb[i]!=me)
        return notify_fail("当着别人的面上树偷桃？不妥不妥。\n");
  dest=__DIR__+(string)this_object()->query("up");
  tell_object(me,"你笨手笨脚地向上爬去。\n");
  me->move(dest);
  tell_room(environment(me),me->query("name")+"笨手笨脚地爬了上来。",me);
  return 1;
}
