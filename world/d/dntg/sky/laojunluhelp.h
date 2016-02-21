int leave_here(string arg,object who)
{
// avoid players' help
  int i;
  object *obs = all_inventory(environment(who));

  i=sizeof (obs);
  while (i--)
    {
    if (living (obs[i]) && obs[i]!=who && userp(obs[i]))
      {
       tell_object(obs[i],arg
           +"向你一拱手道：今日天庭有难，请各位不相干的朋友先避一避！\n");
       tell_object(obs[i],"说着，"+arg+"将你引了出来。\n");
       obs[i]->move("/d/dntg/sky/nantian");
       tell_room(environment(obs[i]),obs[i]->name()+"走了过来。\n",who); 
      } 
    }

return 1;
}

int you_leave(string arg,object who)

{
// avoid players' help

  if(userp(who)){
   tell_object(who,arg
           +"向你一拱手道：今日天庭有难，请各位不相干的朋友先避一避！\n");
   tell_object(who,"说着，"+arg+"将你引了出来。\n");
   who->move("/d/dntg/sky/nantian");
   tell_room(environment(who),who->name()+"走了过来。\n",who); 
   }
   return 1;
}

