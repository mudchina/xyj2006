
varargs void message_vision(string msg, object me, object you)
{
  string my_gender, your_gender, my_name, your_name;
  string str1, str2, str3;
  object *list = all_inventory(environment(me));
  int i = sizeof (list);

  my_name= me->name();
  my_gender = me->query("gender");
  str1 = replace_string(msg,  "$P", gender_self(my_gender));
  str1 = replace_string(str1, "$N", gender_self(my_gender));
  str3 = replace_string(msg,  "$P", my_name);
  str3 = replace_string(str3, "$N", my_name);
  if (you)
  {
    your_name= you->name();
    your_gender= you->query("gender");
    str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
    str2 = replace_string(str2, "$p", gender_self(your_gender));
    str2 = replace_string(str2, "$N", my_name);
    str2 = replace_string(str2, "$n", gender_self(your_gender));
    str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
    str1 = replace_string(str1, "$n", your_name);
    str3 = replace_string(str3, "$p", your_name);
    str3 = replace_string(str3, "$n", your_name);
  }
  while (i--)
  {
    object ob = list[i];
    if (! ob->is_character())
      continue;
    else if (ob == me)
      tell_object(ob,str1);
    else if (ob == you)
      tell_object (ob,str2);
    else if (! ob->query("env/brief_message"))
      tell_object (ob,str3);
  }
}

