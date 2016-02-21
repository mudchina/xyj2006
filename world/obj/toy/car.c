// by snowcat 5/3/1997

#include <ansi.h>

inherit ITEM;

mapping chinese_dirs = ([
  "north":        "北",
  "south":        "南",
  "east":         "东",
  "west":         "西",
  "northup":      "北边",
  "southup":      "南边",
  "eastup":       "东边",  
  "westup":       "西边",
  "northdown":    "北边",
  "southdown":    "南边",
  "eastdown":     "东边",
  "westdown":     "西边",
  "northeast":    "东北",
  "northwest":    "西北",
  "southeast":    "东南",
  "southwest":    "西南",
  ]);

mapping left_dirs = ([
  "north":        "northwest",
  "south":        "southeast",
  "east":         "northeast",
  "west":         "southwest",
  "northeast":    "north",
  "northwest":    "west",
  "southeast":    "east",
  "southwest":    "south",
  ]);

mapping right_dirs = ([
  "north":        "northeast",
  "south":        "southwest",
  "east":         "southeast",
  "west":         "northwest",
  "northeast":    "east",
  "northwest":    "north",
  "southeast":    "south",
  "southwest":    "west",
  ]);

string *makes = ({
  "Acura NXL",
  "Audi Cabriolet",
  "BMW 850",
  "Buick Skylark",
  "Cadillac Seville",
  "Chevrolet Monte Carlo",
  "Chrysler Sebring Convertable",
  "Dodge Viper",
  "Eagle Vision",
  "Ford Thunderbird",
  "Geo Metro",
  "Honda Accord",
  "Hyundai Sonata",
  "Infinti Q45",
  "Jaguar",
  "Lexus SC400",
  "Lincoln Towncar",
  "Mazda Protege",
  "Mercedes-Benz SLK-CLASS",
  "Mercury Tracer",
  "Mitsubishi Mirage",
  "Nissan Maxima",
  "Oldsmobile Aurora",
  "Plymouth Neon",
  "Pontiac Sunfire",
  "Porsche Boxster",
  "Saab 9000",
  "Saturn",
  "Subaru Legacy",
  "Suzuki Esteem",
  "Toyota Camry",
  "Volksvagon Passat",
  "Volvo 960",
  });

void create()
{
  string name = makes[random(sizeof(makes))]+" 轿车";

  set_name(name, ({"car", "che"}));
  set_weight(300000);
  set_max_encumbrance (1000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("short", name+"(Car)");
    set("long", "这是一辆"+name+"。\n");
    set("unit", "辆");
    set("material", "metal");
    set("value", 1000000);
    set("dir", "north");
    set("speed", 0);
    set("fuel", 10000);
    set("miles", 0);
  }
  setup();
}

void automate();

int init()
{
  add_action("do_enter", "enter");
  add_action("do_out", "out");
  add_action("do_look", "look");
  add_action("do_left", "4");
  add_action("do_right", "6");
  add_action("do_speedup", "8");
  add_action("do_slowdown", "2");
  add_action("do_stop", "5");
  add_action("do_handdrive", "7");
  add_action("do_autodrive", "9");
  automate();
  return 1;
}

int test_busy ()
{
  object me = this_object();
  object who = this_player();

  if (me->query_temp("is_busy"))
  {
    tell_object (who,"动作别太猛，车子会搞坏的！\n");    
    return 1;
  }
  me->set_temp("is_busy",1);
  remove_call_out ("reset_busy_temp");
  call_out ("reset_busy_temp",1,me);
  return 0;
}

void reset_busy_temp (object me)
{
  me->set_temp("is_busy",0);  
}

int is_in ()
{
  object me = this_object();
  object who = this_player();
  return environment(who) == me; 
}

int is_driver ()
{
  object me = this_object();
  object who = this_player();

  if (me->query("driver") != who)
  {
    tell_object (who,"别乱动，你又不是司机！\n");  
    return 0;
  }
  return 1;
}

int report_outside_objects ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mixed *inv = all_inventory(where);
  int i;

  if (sizeof(inv) <= 1)
    return 1;

  tell_object (who,"外面有：");  
  for (i=0; i < sizeof(inv); i++)
  {
    if (inv[i] != me)
      tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_inside_objects ()
{
  object me = this_object();
  object who = this_player();
  mixed *inv = all_inventory(me);
  int i;

  if (sizeof(inv) == 0)
    return 1;

  tell_object (who,"车里有：");  
  for (i=0; i < sizeof(inv); i++)
  {
    tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_dir ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mapping exits = where->query("exits");
  string *dirs;
  int i;

  if (! exits)
    return 1;

  dirs = keys(exits);

  tell_object (who,"四面的出口是：");  
  for (i=0; i < sizeof(dirs); i++)
  {
    tell_object (who,chinese_dirs[dirs[i]]+"("+dirs[i]+")");    
  }
  tell_object (who," [车头朝向："+chinese_dirs[me->query("dir")]+
                   "("+me->query("dir")+")]\n");  
  return 1;
}

int report_view ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  tell_object (who,"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");  
  tell_object (who,"从车窗里可以看到：");  
  tell_object (who,where->query("short")+"\n");  
  tell_object (who,where->query("long")+"\n");  
  report_outside_objects();
  report_dir();
  tell_object (who,"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");  
  return 1;
}

int report_short ()
{
  object me = this_object();
  object who = this_player();
  string strspeed, strfuel, strmiles;
  int i, len = 15;

  strspeed = "速度："+sprintf("%d",me->query("speed"));
  strfuel  = "汽油："+sprintf("%d",me->query("fuel")) ;
  strmiles = "里程："+sprintf("%d",me->query("miles"));
  for (i = sizeof(strspeed); i < len; i++)
    strspeed = strspeed + " ";
  for (i = sizeof(strfuel); i < len; i++)
    strfuel = strfuel + " ";
  for (i = sizeof(strmiles); i < len; i++)
    strmiles = strmiles + " ";
  tell_object (who,"\n");  
  tell_object (who,"  □□□□□□□□□□□□□□□□□□□□□□\n");  
  tell_object (who,"  □"+ strspeed + " 7[手导] 8[加速] 9[自导] □\n");  
  tell_object (who,"  □"+ strfuel  + " 4[左转] 5[刹车] 6[右转] □\n");  
  tell_object (who,"  □"+ strmiles + "         2[减速]         □\n");  
  tell_object (who,"  □□□□□□□□□□□□□□□□□□□□□□\n");  
  if (me->query("autodrive") > 0)
    tell_object (who,"  方向控制：全自动");  
  else
    tell_object (who,"  方向控制：手动");  
  if (me->query("driver"))
    tell_object (who,"  司机："+me->query("driver")->query("name"));  
  tell_object (who,"\n");  
  report_inside_objects();
  return 1;
}

int do_enter (string arg)
{
  object me = this_object();
  object who = this_player();

  if (arg != "car")
    return 0;

  if (is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"跳进正在行驶的车子会有生命危险！\n");  
    return 1;
  }

  message_vision ("$N一弯腰，坐进车。\n",who);
  who->move(me);
  if (! me->query("driver") ||
      environment(me->query("driver")) != me)
  {
    me->set("driver",who);
    message_vision ("$N坐在司机座位上。\n",who);
  }
  else
    message_vision ("$N坐在客座上。\n",who);
  return 1;
}

int do_out (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"跳出正在行驶的车子会有生命危险！\n");  
    return 1;
  }

  if (me->query("driver") == who)
  {
    me->set("driver",0);
  }

  message_vision ("$N一打开车门跳下车。\n",who);
  who->move(environment(me));
  message_vision ("$N跳出车，将车门关上。\n",who);
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
  {
    if (arg == "car")
    {
      tell_object (who,"这是一"+me->query("unit")+me->query("name")+
                   "(enter)。\n");
      return 1;
    }
    return 0;
  }
  report_view();
  report_short();
  return 1;
}

int do_left (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"先将车子发动起来再转弯。\n");
    return 1;  
  }

  dir = left_dirs[dir];
  tell_object (who,"你将方向盘向左一转。\n");  
  message_vision (me->query("name")+"车头朝"+chinese_dirs[dir]+
                  "一拐……\n",me);
  me->set("dir",dir);
  return 1;
}

int do_right (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"先将车子发动起来再转弯。\n");
    return 1;  
  }

  dir = right_dirs[dir];
  tell_object (who,"你将方向盘向右一转。\n");  
  message_vision (me->query("name")+"车头朝"+chinese_dirs[dir]+
                  "一拐……\n",me);
  me->set("dir",dir);
  return 1;
}

int do_speedup (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    s += 2+random(4);
    tell_object (who,"你点火发动车子。\n");  
    message_vision (me->query("name")+"轻吼了一声，排气管吐出一股青烟\n",me);
  }
  else if (s < 45)
  {
    s += 4+random(8);
    tell_object (who,"你踩了一踩油门。\n");  
    message_vision (me->query("name")+"轻轻地加速。\n",me);
  }
  else if (s < 90)
  {
    s += 8+random(16);
    tell_object (who,"你用力踩了一踩油门。\n");  
    message_vision (me->query("name")+"嗖地一声加快了时速！\n",me);
  }
  else 
  {
    s += 16+random(32);
    tell_object (who,"你使劲地了踩了一踩油门。\n");  
    message_vision (me->query("name")+"发疯似地加速！\n",me);
  }
  if (s > 320)
    s = 320;
  me->set("speed",s);
  return 1;
}

int do_slowdown (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"车子已经停了。\n");  
  }
  else if (s < 45)
  {
    s -= 4+random(8);
    tell_object (who,"你轻轻地踩了踩闸。\n");  
    message_vision (me->query("name")+"慢慢减速。\n",me);
  }
  else if (s < 90)
  {
    s -= 8+random(16);
    tell_object (who,"你踩了踩闸。\n");  
    message_vision (me->query("name")+"明显地慢了下来。\n",me);
  }
  else 
  {
    s -= 16+random(32);
    tell_object (who,"你使劲地踩了一踩闸。\n");  
    message_vision (me->query("name")+"在飞弛中减速。\n",me);
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_stop (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"车子已经停了。\n");  
  }
  else if (s < 20)
  {
    s = 0;
    tell_object (who,"你猛地一刹车。\n");  
    message_vision (me->query("name")+"轻轻一颠，停了。\n",me);
  }
  else if (s < 45)
  {
    s = 0;
    tell_object (who,"你一个急刹车！\n");  
    message_vision (me->query("name")+"突然急剧地减速！\n",me);
    message_vision (me->query("name")+"发出一声长长的尖叫，吱一声停了！\n",me);
    tell_object (who,"你猛地跄了一下！\n");  
  }
  else if (s < 100)
  {
    s -= 40+random(40);
    tell_object (who,"你疯狂地踩闸急刹车！\n");  
    message_vision (me->query("name")+"突然急剧地减速！\n",me);
    message_vision (me->query("name")+"剧烈地震动着！\n",me);
    tell_object (who,"你一阵头晕，差一点吐了出来！\n");  
  }
  else 
  {
    s -= 60+random(60);
    tell_object (who,"你不顾一切地地踩闸急刹车！\n");  
    message_vision (me->query("name")+"突然急剧地减速！\n",me);
    message_vision (me->query("name")+"可怕地震动着，地上划出两道黑印！\n",me);
    tell_object (who,"强烈的震动中你一阵剧烈头痛！\n");  
    //who->unconcious();
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_handdrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",0);
  tell_object (who,"现在手动控制行车方向。\n");  
  return 1;
}

int do_autodrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",1);
  tell_object (who,"现在全自动控制行车方向。\n");  
  return 1;
}

void collision ()
{
  object me = this_object();
  object who = me->query("driver");
  int s = me->query("speed");
  string *hits = ({
    "冲出了路",
    "滑进路边的草丛中",
    "撞进一个大土堆",
    "滑进一滩烂泥",
    "闯进一个小木棚",
    "冲向一大丛灌木丛",
    "撞向一片小树",
  });
  string how;

  if (s == 0)
    how = "极轻地";
  else if (s < 20)
    how = "咣当一声";
  else if (s < 40)
    how = "哗啦一声";
  else if (s < 60)
    how = "砰地一声";
  else if (s < 80)
    how = "轰地一声";
  else if (s < 100)
    how = "象脱缰野马一样地";
  else if (s < 150)
    how = "极疯狂地";
  else 
    how = "天塌地裂般地";

  if (s < 50)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "。\n",me);
    message_vision (me->query("name")+"停了下来。\n",me);
  }
  else if (s < 100)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "！\n",me);
    message_vision (me->query("name")+"在一阵强烈的震动中停了下来！\n",me);
    tell_object (who,"你一阵目眩！\n");  
  }
  else
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "！\n",me);
    message_vision (me->query("name")+"在一阵极可怕的震动中发出巨响！\n",me);
    message_vision ("一切又突然安静了下来停了下来。\n",me);
    tell_object (who,"你一刹那觉得窗外的所有东西向你猛地扑来又突然停止！\n");  
    //who->unconcious();
  }
  me->set("speed",0);
}

void display_me ()
{
  object me = this_object();
  string name = me->query("name");
  int s = me->query("speed");
  string msg = 0;

  if (s == 0)
  {
    set("short", "停在路上的"+name+"(Car)");    
  }
  else if (s < 30)
  {
    set("short", "慢慢行驶的"+name+"(Car)");
    msg = name+"慢慢地驶着。\n";
  }
  else if (s < 50)
  {
    set("short", "行驶中的"+name+"(Car)");
    msg = name+"正在行驶着。\n";
  }
  else if (s < 110)
  {
    set("short", "飞驶的"+name+"(Car)");
    msg = name+"飞快地行驶着。\n";
  }
  else 
  {
    set("short", "狂驶中的"+name+"(Car)");
    msg = name+"发疯似地狂驶着。\n";
  }
  if (msg && 
      random(10) == 0)
    message_vision (msg,me);
}

void check_speed ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") <= 0)
  {
    me->set("speed",0);
    message_vision (me->query("name")+"奇怪地冒出一股青烟，没有燃油了。\n",me);
    message_vision (me->query("name")+"有气无力地停了。\n",me);
  }

  if (me->query("speed") > 0 &&
      (! me->query("driver") ||
        environment(me->query("driver")) != me))
  {
    me->set("speed",0);
    message_vision (me->query("name")+"没有司机了。\n",me);
    message_vision (me->query("name")+"吱地一声歪歪斜斜地停了。\n",me);
  }
}

void check_fuel ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") > 0)
  {
    int f = me->query("fuel");

    f -= (me->query("speed")/10+1); 
    if (f < 0)
      f = 0;
    me->set("fuel",f);
  }
}

void check_miles ()
{
  object me = this_object();

  if (me->query("speed") > 0)
  {
    me->add("miles",me->query("speed")/6);
  }
}

object find_room (string dest)
{
  object me = this_object();
  object where = environment(me);

  if (!dest)
    return 0;
  return find_object(dest);
}

object find_exit ()
{
  object me = this_object();
  object where = environment(me);
  object who = me->query("driver");
  string dir = me->query("dir");
  object obj = 0;
  mapping dirs;
  string dest;

  if (!mapp(dirs = where->query("exits")))
  {
    tell_object (who,"这里好象没有什么路可行了。\n");
    return 0;  
  }

  while (obj == 0)
  {
    dest = dirs[dir];
    if (dest)
      obj = find_room(dest);
    if (!dest || !obj)
    {
      dest = dirs[dir+"down"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      dest = dirs[dir+"up"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"前方("+chinese_dirs[dir]+
                           ")没有什么路可行了。\n");
        return 0;
      }  
    }

    if (! obj->query("outdoors"))
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"前方("+chinese_dirs[dir]+
                           ")不是汽车可行的路。\n");
        return 0;
      }  
    }
    
    if (me->query("car_from/"+where->query("short"))==obj->query("short") &&
        me->query("autodrive") &&
        random(20))
      obj = 0;
  }
  if (me->query("autodrive"))
  {
    if (random(3) == 0)
      tell_object (who,"汽车现在向"+chinese_dirs[dir]+"行驶。\n");
    me->set("dir",dir);
  }
  return obj;
}

void check_move ()
{
  object me = this_object();
  object where = environment(me);
  object exit = 0;

  if (me->query("speed") == 0)
    return;

  exit = find_exit();
  me->add("distance",me->query("speed")/5+1);
  if (me->query("distance") < 100)
    return;

  me->set("distance",0);
  if (! exit)
  {
    remove_call_out("collision");
    call_out ("collision",1);
  }
  else
  {
    me->set("car_from/"+exit->query("short"),where->query("short"));
    message_vision (me->query("name")+"开出"+where->query("short")+"。\n",me);
    me->move(exit);
    message_vision (me->query("name")+"开进"+exit->query("short")+"。\n",me);
  }
}

void automate ()
{
  check_speed ();
  check_fuel ();
  check_miles (); 
  display_me ();
  remove_call_out("check_move");
  call_out("check_move",2); 
  remove_call_out("automate");
  call_out("automate",5);
}
