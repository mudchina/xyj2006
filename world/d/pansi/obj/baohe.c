#include <ansi.h>
#include <dbase.h>
#include <armor.h>

//inherit F_AUTOLOAD;  
inherit ITEM;
inherit F_UNIQUE;
object focusobj;

void create()

{
     set_name(CYN"月光宝盒"NOR, ({ "yueguang baohe","he","baohe" }) );
     set_weight(100);
     set("long","这就是西游记传说中齐天大圣和紫霞仙子爱情见证，的据说有瞬间移动(move)的作用。\n");
     set("value", 0);
     set("material", "steel");
     set("no_drop", "这么难得的令牌还是留着吧。\n");
     set("unit", "块");
}


void init()
{
if (this_player() -> query("family/family_name") != "盘丝洞" ) {
remove_call_out("free_jingu");
call_out("free_jingu", 10, this_object(), this_player()); 
}
   add_action("do_move", "move");
   add_action("do_mark", "mark");
::init();
}


int do_move()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("打架中你还有哪只手有空去月光宝盒呢？\n");
 if(me->is_busy())
     return notify_fail("你正忙着呢......\n");
  if(me->query("baohe")>20)
        {
      me->set("baohe",0);
        tell_object(me,HIY"你刚要念咒语，突然发觉手中的月光宝盒正在逐渐融化，只有眼睁睁
看着它化为一阵白烟消失在空气中。\n"NOR);   
        destruct(this_object());
        return 1;
       }


  if( !query("mark_place") ) return notify_fail("先用 mark 在目的地做上记号。\n");

 tell_room(environment(me),HIY+me->query("name")+"把从怀中拿出月光宝盒放在地上,仰面大吼:\n"HIR"
    『波若波罗密,波若波罗密~~~~』\n"HIY
      
                        "一时狂沙漫天..... "
                        "等你张开眼时,"+me->query("name")+"的身影已经消失在漫天风沙之中.\n\n"NOR,me);
 
       tell_object(me,HIY"你双眼微闭，嘴中念起八卦阴阳咒："
                        "「波若波罗密乾坤大法，走！」\n"
                        "你的身影已经消失在漫天风沙之中.\n"NOR);
tell_room(environment(me),HIG"身后传来众人的惊呼：“哇～～～～～升天啦～～～～”\n"NOR,me);

        me->move(query("mark_place"));
                message_vision(HIY"$N的身影突然出现在一阵狂风之中。\n"NOR, me);
             me->add("baohe",1);

       return 1;
}


int do_mark()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("打架中你还有哪只手有空去拿宝盒呢？\n");
if (this_player() -> query("family/family_name") != "盘丝洞" ) {
tell_object(me, HIR"你仿佛听到有人说：非我门人，得之无用。\n"
+ "随着一声轻响，月光宝合已腾空而去，不留下一丝痕迹。\n\n"NOR);
destruct(this_object());
return 1;
}

  if(me->query("baohe")>20)
         {
      me->set("baohe",0);
        tell_object(me,HIY"你刚要念咒语，突然发觉手中的月光宝盒正在逐渐融化，只有眼睁睁
看着它化为一阵白烟消失在空气中。\n"NOR);   
        destruct(this_object());
        return 1;
       }

  set("mark_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"紧握手中月光宝盒，嘴里请轻念了几句咒语。\n"NOR,me);
 
  tell_object(me,"你紧握手中月光宝盒，嘴里请轻念了几句咒语。\n"
            +HIY"突然从宝盒中射出一道光柱直冲云霄～。\n"NOR);
       return 1;
}

//int query_autoload() { return 1; }

void free_jingu(object ob, object who)
{
        if(!who || !ob) return;
        if (who -> query("family/family_name") != "盘丝洞" ) {
             tell_object(who, HIR"你仿佛听到有人说：非我门人，得之无用。\n"
       + "随着一声轻响，月光宝合已腾空而去，不留下一丝痕迹。\n\n"NOR);
        destruct(ob);
   }
  else { 
           call_out("free_jingu", 10, ob, who);
  }
    return;
}
