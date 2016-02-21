
inherit ITEM;
inherit F_FOOD;

string *food_name= ({"麻辣肚丝",
                "松仁玉米",
		"梅菜扣肉",
		"五香腊肠",
		"鱼香肉丝",
		"红油鸡片",
		"清炒虾仁",
		"五花焖肉",
		"青丝熏鱼",
		"糖醋排骨",
		"京酱肉丝",
		"油炝大虾",
		"脆皮烤鸭",
		"红烧素鹅",
		"宫保鸡丁",
		"麻辣肚丝",
		"红油肺片",
		"嫩汆猪肝",
		"走油脆肠",
		"爆炒腰花",
		"麝香冬笋",
		"翡翠豆腐",
		"麻婆豆腐",
		"三鲜腐竹",
});

string *eat_msg=({
	  "$N拿起玉筷夹了些$name，放到嘴中吃了起来。\n",
	  "$N吃了一大口$name。\n",
	  "$N尝了尝$name。\n",
	  "$N夹了些$name，放到嘴中。\n",
	  "$N细细品尝着$name。\n",
	  });

void create()
{	string name = "婚礼大菜";
  	set_name(name, ({"food"}));
  	set_weight(1000);
  	if (clonep())
   		 set_default_object(__FILE__);
  	else {
    		set("long", "一盘令人垂涎的婚礼大菜。\n");
    		set("unit", "盘");
//		set("eat_msg", "$N拿起玉筷夹了些" + name + "，放到嘴中吃了起来。\n");
    		set("value", 250);
    		set("food_remaining", 5);
    		set("food_supply", 20);
  	}
}

void init ()
{
	if (query("name")=="婚礼大菜")
	{
		string name;
		name=food_name[random(sizeof(food_name))];
  		set_name(name, ({"food"}));
		set("long", "一盘令人垂涎的"+name+"。\n");
//		set("eat_msg", "$N拿起玉筷夹了些" + name + "，放到嘴中吃了起来。\n");
	}
        if(!wizardp(this_player())) {
        	set("no_get", "在婚礼上这么干似乎不大好吧！\n");
        }
        add_action("do_get", "get");
        add_action("do_eat", "eat");
	::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();
  string name=query("name");
  int i;

  set("eat_msg", replace_string(eat_msg[random(sizeof(eat_msg))],
	  "$name",name));
  i=::do_eat(arg);
  if(i && name=="松仁玉米") {
      if(!who->query_temp("xifuhui_eatcorn")) {
       if(who->query("gender")=="女性" && who->query("married")) {
	  string id;
	  if(id=who->query("couple/id")) {
	      object ob;
	      if(ob=present(id, environment(me))) {
		  message_vision("众人看着$N和$n，齐声大笑道："+
			  "哈！松仁玉米！恭喜！恭喜！\n",who,ob);
		  who->add_temp("xifuhui_eatcorn",1);
		  // this will be used in born child later.
	      }
	  }
       }
      }
  }
  return i;
}

int do_get (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg)
    return 0;

  if (present(arg,environment(who))==me)
  {
    tell_object(who,"在婚礼上这么干似乎不大好吧！\n");
    return 1;
  }
  return 0;
}

