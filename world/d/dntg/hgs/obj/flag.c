// sgzl

inherit ITEM;

void create()
{
        set_name("大旗", ({"flag","qi"}));
        set("unit", "面" );
        set_weight(500);
        set("long", @LONG
       ***********************************************
       **      得此旗者可为仙灵福地水帘洞之洞主     **
       ***********************************************
LONG);
}

void destruct_me(object where, object me)
{
  message_vision("一阵清风吹过，$n化作一团灰烬。\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

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
