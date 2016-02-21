// snowcat

void greeting1 (object who)
{
  object me = this_object();

  if (! visible (who))
    return;
  if (me->is_fighting())
    return;

  if (who->query("qujing/number") > 0)
  {
    string str;
    object weapon = me->query_temp("weapon");

    if (weapon)
      str = "$N举起手中的"+weapon->query("name")+"向$n行礼：";
    else
      str = "$N举手向$n行礼：";
    str = str + RANK_D->query_respect(who)+"西行取经，威名亘古！\n";

    message_vision (str,me,who);
  }
}

void greeting2 (object who)
{
  object me = this_object();

  if (! visible (who))
    return;
  if (me->is_fighting())
    return;

  if (who->query("quest/reward") > 0)
  {
    string str;
    str = "$N向$n一躬："+RANK_D->query_respect(who)+
          "仙体祥云笼罩，请速去拜见吾王太宗！\n";
    message_vision (str,me,who);
  }
}
