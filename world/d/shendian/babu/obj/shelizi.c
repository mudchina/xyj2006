//copy from bone by repoo

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
  set_name(HIR"舍利子"NOR, ({"sheli zi"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "天神帝释坐化所形成的舍利子。\n");
     set("unit", "个");
    set("material", "bone");
  }
 set("no_sell", 1);
 set("no_drop", 1);
 set("no_put",1);
 set("no_give",1);

  setup();
}
int init()
{
        add_action("do_mo","mo");
        check_owner();
        return 1;
}
int do_mo(string arg)
{
        string type;
        object who = this_player();
        object ob;

        if(who->is_fighting())
           return notify_fail("打完了再说。\n");
        if(who->is_busy())
           return notify_fail("你正忙着呢!\n");
    if (!arg)
 return notify_fail("你想让舍利子变成什么兵器？(sword blade stick hammer fork axe spear staff whip mace)\n");
        else 
        {
                sscanf(arg,"%s",type);
                        switch(type)
                        {
                        case "sword":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 湛卢"NOR+HIW"剑 \n"NOR,who);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 湛卢"+HIW"剑 "NOR+YEL"了！\n\n"+NOR,users() );

        ob = new("/d/shendian/babu/obj/gujian");
         ob->move(who);
        destruct(this_object());
                                break;
                         case "blade":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 沉鱼"NOR+HIW"刀 \n"NOR,who);
  message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 沉鱼"+HIW"刀 "NOR+YEL"了！\n\n"+NOR,users() );
         ob = new("/d/shendian/babu/obj/gudao");
          ob->move(who);
         destruct(this_object());
                                 break;
                        case "stick":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 重云"NOR+HIW"棍 \n"NOR,who);
   message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 重云"+HIW"棍 "NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/gustick");
         ob->move(who);
        destruct(this_object());
                                break;
                        case "hammer":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 吟龙"NOR+HIW"锤 \n"NOR,who);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 吟龙"+HIW"锤 "NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/guhammer");
         ob->move(who);
        destruct(this_object());
                                break;
                        case "fork":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 孤凤"NOR+HIW"叉 \n"NOR,who);
  message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 孤凤"+HIW"叉 "NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/gufork");
         ob->move(who);
        destruct(this_object());
                                break;
                        case "axe":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 迸泉"NOR+HIW"斧 \n"NOR,who);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 迸泉"+HIW"斧 "NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/guaxe");
         ob->move(who);
        destruct(this_object());
                                break;
                        case "spear":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 提炉"NOR+HIW"枪 \n"NOR,who);
 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR"提炉"+HIW"枪"NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/guqiang");
         ob->move(who);
        destruct(this_object());
                                break;
                        case "staff":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 降龙"NOR+HIW"杖 \n"NOR,who);
message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR"降龙"+HIW"杖"NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/gustaff");
         ob->move(who);
        destruct(this_object());
                                break;
                       case "whip":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 凝绝"NOR+HIW"鞭 \n"NOR,who);
message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query("name")+"拿到"+HIR" 凝绝"+HIW"鞭 "NOR+YEL"了！\n\n"+NOR,users() );
        ob = new("/d/shendian/babu/obj/guwhip");
         ob->move(who);
        destruct(this_object());
                                break;
                case "mace":
message_vision(WHT"\n$N轻轻的摸了一下"NOR+HIR"舍利子"NOR+WHT"，只见白光一闪，"+
HIR" 舍利子 "NOR+WHT"不由自主的散开，形成一把"NOR+HIR" 丹凤"NOR+HIW"锏 \n"NOR,who);

 message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+who->query
("name")+"拿到"+HIR" 丹凤"+HIW"锏 "NOR+YEL"了！\n\n"+NOR,users() );


        ob = new("/d/shendian/babu/obj/gumace");
        ob->move(who);
        destruct(this_object());
                                break;

}
   return 1;
}

}
