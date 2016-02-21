// created by snowcat
// 5/22/1997

string name_suffix();
string new_unit();

int display_info (object who)
{
  tell_object (who,"请使用：transform <new-english-name> <中文名称>。\n");  
  return 1;
}

int change_success (object me, object ob)
{
  message_vision ("话音未落，只见$N手中突然多出一"+ob->query("unit")+
                  "$n！\n",me,ob);
  return 1;
}

int do_transform (string arg)
{
  string *msgs = ({
    "$N抓起一把$n一嚼喷将出去，口中念念有词。\n",
    "$N把$n丢在口中嚼两下望空一喷，大喝一声。\n",
    "$N将$n往嘴里一嚼，喷在空中喝道：“变”！\n",
    "$N拿起$n往嘴里一扔，哼哈几声嚼将出去！\n",
    "$N将$n往口中一塞咔嚓嚼将起来，念念有词向空一喷。\n",
  });
  object me = this_player();
  object ob = this_object();
  string id, name;

  if (!arg || sscanf(arg,"%s %s",id,name)!=2)
    return display_info(me);

  if (ob->query("has_transformed"))
    return 0;

  if (me->query_skill("spells")<10)
  {
    tell_object (me,"你的法术不够。\n");
    return 1;
  }

  name = name + name_suffix();
  message_vision (msgs[random(sizeof(msgs))],this_player(),this_object());

  ob->set_name(name, ({"my "+id}));
  //ob->set_temp("apply/id",({id, "my "+id}));
  ob->set_temp("apply/id",({"my "+id}));
  ob->set("short",name+"("+capitalize("my "+id)+")");
  ob->set("unit",new_unit());
  ob->set("long","一"+this_object()->query("unit")+name+"。\n");
  ob->set("has_transformed",1);

  call_out ("change_success",1,me,ob);
  return 1;
}

