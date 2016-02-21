//Cracked by Roath
#include <weapon.h>

inherit STAFF;

int steps;

void create()
{
  set_name("鱼竿", ({"yu gan"}));
  set_weight(1000);
  if( clonep() )
  set_default_object(__FILE__);
  else 
    {
    set("long","一个鱼竿，装(zhuang)了蚯蚓后就能用来钓(diao)鱼了，鱼上钩后别忘了提(ti)杆！\n");
    set("unit", "个");
    set("material", "wood");
    set("value", 2000);
    set("wield_msg", "$N把$n扛在肩膀上。\n");
    set("unequip_msg", "$N将$n收了起来。\n");
    }
  set("have_qiuyin",0);
  init_staff(3);
  setup();
}

int init ()
{
  add_action ("do_zhuang", "zhuang");
  add_action ("do_diao", "diao");
  add_action ("do_ti", "ti");
  return 1;
}

int do_zhuang (string arg)
{
  object who=this_player();
  object me=this_object();
  object ob;

  if( (!arg) || (arg != "qiu yin" && arg != "qiuyin" && arg !="蚯蚓") )
        return notify_fail("你要把什么穿在鱼钩上？\n");

  ob=present("qiu yin", who);
  if(! present("qiu yin", who)) 
        return notify_fail("你身上没有这东西。\n");

  if(me->query("have_qiuyin")==1)   
        return notify_fail("钩上已经有蚯蚓了，不用再穿了。\n");

  if (who->query_skill("dodge",1)<20)
        return notify_fail("瞧你笨手笨脚的，这事恐怕作不来。\n");

  message_vision( "$N在鱼钩上穿了一只蚯蚓。\n",who);
  destruct(ob);
  who->start_busy(3);
  me->set("have_qiuyin",1); 

  return 1;  
}



int do_diao (string arg)
{
  object who=this_player();
  object me=this_object();
  object where;

  where=environment(who);

  if( (!arg) || (arg != "fish" && arg != "yu" && arg !="鱼") )
        return notify_fail("你要钓什么？\n");

  if (where->query("can_fish") != 1)
         return notify_fail("这里不能钓鱼。\n");

  if(me->query("have_qiuyin")!=1)   
        return notify_fail("钩上什么都没有，怎么钓？\n");

  if(who->query("is_fishing") ==1)   
        return notify_fail("你已经钓着鱼了。\n");

  if(! me->query("equipped") )
         return notify_fail("你必须把杆装备上才能钓。\n");

  message_vision("$N将鱼钩远远向河里一抛，坐下来开始钓鱼。\n",who);
  steps=0;
  who->set("is_fishing", 1);
  who->start_busy(10);
  remove_call_out ("fishing");
  call_out ("fishing",10,who);
  who->add("sen", -30);

  return 1;
}

int fishing (object who)
{
  object me=this_object();
  string *msg = ({
  "水面上一点动静也没有。\n",
  "河水泛起一片涟漪。\n",
  "一个小水花逐渐靠向浮子。\n",
  "浮子抖动了两下。\n",
  "浮子开始颤抖着。\n",
  "水面又恢复了平静。\n",
});

  if (who->query("sen")<30) 
    {
    message_vision("$N一不留神，手中的钓竿掉落在水中。\n",who);
    who->delete("is_fishing");
    destruct(me);
    return 1;
    }

  message_vision(msg[steps],who);
  if (random(2)==1)
    {
    if (steps !=5) steps++;
    else steps=0; 
    }
  who->add("sen", -30);
  who->start_busy(10);
  remove_call_out ("fishing");
  if(who->query("is_fishing") ==1 
       && me->query("equipped") &&  who=environment(me))
     call_out ("fishing",10,who);
  return 1;
}

int do_ti()
{
  object who=this_player();
  object me=this_object();
  object where;
  object fish;

  if(who->query("is_fishing") !=1)   
        return notify_fail("杆不就在你手里吗？还提什么劲？\n");

  set("have_qiuyin",0);
  message_vision("$N突然将手中的鱼杆疾速上提，",who);
  if (steps ==4 && random(2)==1) 
    {
    fish=new("/d/southern/jinghe/obj/fish");
    fish->move(who);
    message_vision("结果钓上了一条"+fish->query("name")+"！\n",who);
    who->delete("is_fishing");
    return 1;
    }

  if (steps ==4 || steps ==3) 
    {
    message_vision("太可惜了，鱼没钓着：（\n",who);
    who->delete("is_fishing");
    return 1;
    }
  else 
    {
    fish=new("/d/southern/jinghe/obj/trash");
    fish->move(who);
    message_vision("$N只觉得鱼杆沉沉的，奋力一提，上来了一"
      +fish->query("unit")+fish->query("name")+"！\n",who);
    who->delete("is_fishing");
    return 1;
    } 
  return 1;
}
