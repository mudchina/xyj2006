void set_my_killer_list(object killer, object victim);

int valid_kill(object killer, object victim, int no_list)
{    
    
    if(userp(victim)&&userp(killer)&&!wizardp(killer)&&(!killer->query_temp("pkgame"))&&(!victim->query_temp("pkgame")))
    {
     if(victim->query("combat_exp")<100000)
       		return notify_fail("为了世界更美好，放过新手吧!\n");
        
     if(killer->query("combat_exp")<100000||killer->query("daoxing")<100000)
                return notify_fail("自己功夫没练好，这种事还是少想！\n");
     if(killer->query("PKS")>killer->query("MKS")/1000)
               return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
     if(killer->query_condition("no_pk_time"))
              return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");
     if(!killer->query("env/PK"))
                return notify_fail("你已经设定了不对Player下kill命令,\n如果确实有深仇大恨,请用unset PK解除!\n");
      if(((int)killer->query("tongji/pktime")>2||killer->query("mud_age")-killer->query("tongji/mudage")<30000)&&!wizardp(killer))
   		return notify_fail("你近来杀人太多了。\n");
   
    }
    if (victim->query("taskguai"))
    {
    	if( victim->query("owner") && killer != victim->query("owner") )
               	return notify_fail(victim->query("name")+"瞪了你一眼，你连忙闪一边去了。\n");
    }
           
     return 1;
}

void set_my_killer_list(object killer, object victim)
{
     string *list, *listk;
     string kill;

         listk=killer->query_temp("my_killer_list");
         if(listk && arrayp(listk)) {
             if(member_array(victim->query("id"),listk)!=-1) {
                 return;
             }
         }
         list=victim->query_temp("my_killer_list");
         kill=killer->query("id");
         if(!list) list=({kill});
         else if(member_array(kill, list)==-1)
             list+=({kill});
         if(sizeof(list)>100)
             list=list[1..<1]; 
         victim->set_temp("my_killer_list", list);
}
