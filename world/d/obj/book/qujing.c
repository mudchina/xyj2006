
inherit ITEM;
void create()
{
  set_name("〖无字经〗", ({"wuzi jing", "jing", "book"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "本");
    set("material", "paper");
    set("value", 0);
  //  set("no_put",1);
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("long", "一本薄薄的无字经。\n");
  }
}
void init ()
{
  object me = this_object();
  object who = this_player();
  object where = environment();
  add_action ("do_read", "read");
  add_action ("do_read", "study");
  add_action ("do_read", "du");
  add_action ("do_decide", "decide");
  if (! me->query("my_owner") &&
      interactive (who))
    me->set("my_owner",who->query("id"));
   
     if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
    
}

void destruct_me(object where, object me)
{
  message_vision("千面怪鬼鬼祟祟地拿起$n撒脚就跑,快追!\n",where,me);
  destruct (me);
}


void set_skill (string str)
{
  set("skill", ([
                "name": str,
                "exp_required": 10000,
                "sen_cost": 25,
                "difficulty": 25,
                "max_skill": 200,
  ]));
}
mapping skills = ([
  "archery": "基本弓箭",
  "axe": "基本斧法",
  "blade": "基本刀法",
  "dagger": "短兵刃",
  "dodge": "基本轻功",
  "fork": "基本叉法",
  "hammer": "基本锤法",
  "mace": "基本锏法",
  "parry": "拆招卸力之法",
  "rack": "基本钯法",
  "spear": "基本枪法",
  "staff": "基本杖法",
  "stick": "基本棍法",
  "sword": "基本剑术",
  "throwing": "暗器使用",
  "whip": "基本鞭术",
  "unarmed": "扑击格斗之技",
  "force": "内功心法",
  "spells": "法术",
  "literate": "读书识字",
]);
void show_skills ()
{
  int i;
  int size = sizeof (skills);
  string *strs = keys(skills);

  write ("你可以选择如下技能：\n");
  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size; i++)
  {
    write ("  "+strs[i]+": "+skills[strs[i]]+"\n");
  }
}
int do_decide (string arg)
{
  object me = this_object();
  object who = this_player();
  string *strs = keys(skills);
  string str;
  int i;
  int size = sizeof (skills);
  if (me->query("my_owner") != who->query("id")||! who->query("obstacle/reward"))
  {
    tell_object (who,"天边传来如来佛祖的声音：这本经书不是你的，留之无用，还是还我吧！\n");
    destruct (me);    return 1;
  }

  if (who->query("obstacle/book"))
  {
    str = skills[who->query("obstacle/book")];
    tell_object (who,"你早已决定用无字经学习"+str+"了。\n");
    return 1;
  }

  for (i = 0; i < size; i++)
  {
    if (arg == strs[i])
    {
      str = skills[arg];
      break;
    }
  }

  if (! str)
  {
    show_skills ();
    return 1;
  }
  who->set("obstacle/book",arg);
  me->set_skill(arg);
  tell_object (who,"你决定从此用无字经学习"+str+"。\n");
  tell_object (who,"你可以将"+str+"学习到二百级。\n");
  who->save();
  return 1;
}
int reading (object me, object book)
{
  mapping skill;
  int cost, my_skill,qint;

  if (environment(me)->query("no_fight") && 
      environment(me)->query("no_magic"))
    return notify_fail("安全区内禁止练功。\n");
                    
  if (me->is_fighting())
    return notify_fail("你无法在战斗中专心下来研读新知！\n");

  if (me->is_busy() || me->query_temp("pending/exercising"))
    return notify_fail("你现在正忙着呢。\n");

  if( !me->query_skill("literate", 1) )
    return notify_fail("你是个文盲，先学学读书识字(literate)吧。\n");
  message_vision ("$N正专心地研读$n。\n",me,book);
  skill = book->query("skill");
  my_skill=me->query_skill(skill["name"],1);

  if ((int)me->query("combat_exp") < skill["exp_required"] ||
      ((string)SKILL_D(skill["name"])->type()=="martial"
      && my_skill*my_skill*my_skill/10>(int)me->query("combat_exp")))
  {
    write("你的道行不够，再怎么读也没用。\n");
    return 1;
  }

  notify_fail("以你目前的能力，还没有办法学这个技能。\n");
  if (!SKILL_D(skill["name"])->valid_learn(me))
    return 0;
   qint=me->query_int();
   if(qint>40) qint=40;
  cost = skill["sen_cost"] + skill["sen_cost"] 
         * (skill["difficulty"] - qint)/20;
  if ((int)me->query("sen") < cost)
  {
    write("你现在过于疲倦，无法专心下来研读新知。\n");
    return 1;
  }
  if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
  {
    write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
    return 1;
  }
  me->receive_damage("sen", cost);

  if (!me->query_skill(skill["name"], 1))
    me->set_skill(skill["name"], 0);
  me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/5+5);
  write("你研读有关" + to_chinese(skill["name"]) + "的技巧，似乎有点心得。\n");
  return 1;
}
int do_read (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg ||
      present (arg,who) != me)
    return notify_fail ("你要读什么？\n");

  if (me->query("my_owner") != who->query("id")||! who->query("obstacle/reward"))
  {
//    tell_object (who,"这本经书不是你的。\n");
    tell_object (who,"天边传来如来佛祖的声音：这本经书不是你的，留之无用，还是还我吧！\n");    destruct (me);    return 1;
  }

  if (! me->query("skill"))  
  {
    if (who->query("obstacle/book"))
      me->set_skill(who->query("obstacle/book"));
    else
    {
      tell_object (who,"请使用decide来决定你想用经书学习什么。\n");
      return 1;
    }
  }
  return reading (who,me);
}
