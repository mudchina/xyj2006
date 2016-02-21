inherit ITEM;

void create()
{
        set_name("兵器",({"bing qi"}) );
        set("long","一大捆兵器，刀、枪、剑、戟、斧、钺、钩、叉\n
什么都有，上面都刻有几个大字：＂傲来国制＂。\n");
        set_weight(20000);
        set("unit","捆");
}

void destruct_me(object where, object me)
{
  message_vision("兵器唏哩哇啦撒了一地。\n",where,me);
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
        call_out("destruct_me",5,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

