// by bluewww@YSZZ

#include <ansi.h>

#define SHILI_D "/adm/daemons/shili"
void invite_one(object me,string pos);

string get_pos()
{
        string fname=file_name(this_object());
        string* flist=explode(fname,"/");
        return flist[sizeof(flist)-2];
}

int exp_level(int exp)
{
        int i=0;
        int sum=1;
        
        while(sum<exp){
                sum=sum*10;
                i++;
        }
        return i;
}

int check_exp(int exp,object ob)
{
        int obexp=ob->query("combat_exp");
        int ll,tl;
        
        tl=exp*12/10;
        ll=exp*8/10;
        if(obexp>ll&&obexp<tl)return 1;
        return 0;
}

void init ()
{
    string pos=get_pos();
    string faname=SHILI_D->query_family(pos);
    string mname=SHILI_D->query_master(faname);
    
    this_object()->set("short",mname+"祭台");
    add_action("do_tiaozhan","tiaozhan");
    add_action("do_list","listshili");
}

int do_list()
{
        object me=this_player();
        string pos=get_pos();
        string faname=me->query("family/family_name");
        int shili=SHILI_D->query_shili(pos,faname);
        
        if( ! faname )
        return notify_fail("你还是赶快找个人罩着你吧！\n");
        
        write(faname+"在本地区的势力为："+shili+"\n");
        return 1;
}

int do_tiaozhan()
{
        object me=this_player();
        int exp=me->query("combat_exp");
        string pos=get_pos();
        string faname=SHILI_D->query_family(pos);
        object* inv;
        int i;
        
        if(me->is_busy())
            return notify_fail("你正忙着呢。\n");       
    
        if(exp<100000)
            return notify_fail("你活得不耐烦了，这也敢来找麻烦！\n");
    
        if(me->query("family/family_name")==faname)
            return notify_fail("你到本门的地头上捣什么乱？\n");
    
        if(!me->query("family/family_name"))
             return notify_fail("你又在为谁辛苦为谁忙呢?\n");

        if(me->query_temp("in_tiaozhan"))
            return notify_fail("你已经在挑战中！\n");
        inv=all_inventory();
        for(i=0;i<sizeof(inv);i++)
           if(inv[i]->query_temp("in_tiaozhan"))
                return notify_fail("已有人在这里挑战了，你还是等等吧。\n");
                
        me->set_temp("in_tiaozhan",1);
        write(GRN+SHILI_D->query_master(faname)+"的神像突然开口说道："+RANK_D->query_rude(me)+"你等着，我去找一个人和你比试比试！\n"+NOR);
        invite_one(me,pos);        
        return 1;           
}

void invite_one(object me,string pos)
{
        object* list=users();
        object* canusers=({});
        int i=sizeof(list);
        string faname=SHILI_D->query_family(pos);
        int exp=me->query("combat_exp");
        
        while(i--){
            if(list[i]->query("family/family_name")!=faname)
                continue;
            if (!environment(list[i]))
                        continue;
            if (list[i]->is_fighting())
                        continue;
            if (list[i]->is_busy())
                        continue;
            if (list[i]->query_temp("no_move"))
                        continue;
            if (list[i]->is_ghost())
                        continue;
            if (!living(list[i]))
                        continue;
            if(list[i]->query_temp("in_tiaozhan"))
                        continue;       
            if(list[i]->query_temp("ask_yingzhan"))
                        continue;               
    
            if(exp<list[i]->query("combat_exp")&&list[i]->query("combat_exp")<exp*10)
               canusers+=({list[i]});
        }
        if(sizeof(canusers)>0){
             i=random(sizeof(canusers));
                        
          canusers[i]->set_temp("ask_yingzhan",1);
          canusers[i]->set_temp("yingzhan_place",file_name(this_object()));
          canusers[i]->set_temp("yingzhan_man",me);
          canusers[i]->set_temp("no_move",1);
          tell_object(canusers[i],"你耳边传来"+SHILI_D->query_master(faname)+"的声音：
有人在"+SHILI_D->query_chinese(pos)+"挑战本门的势力，限你在30秒内马上去应战(yingzhan)！\n");
           call_out("check_yingzhan",30,me,canusers[i],faname);
            return;
        }
        write(GRN+SHILI_D->query_master(faname)+"的神像说道：本门现在没有合适的人选，"+RANK_D->query_rude(me)+"，便宜你了。\n"NOR);
        me->delete_temp("in_tiaozhan");
        me->delete_temp("no_move");
        return;
}

void check_yingzhan(object me,object target,string faname)
{
        if(environment(target)!=this_object()
            &&target->query_temp("ask_yingzhan")){
               tell_object(target,GRN"你耳边传来"+SHILI_D->query_master(faname)+"的声音："+RANK_D->query_rude(target)+"，居然对本掌门不理不睬！\n"NOR);
               write(GRN+SHILI_D->query_master(faname)+"的神像沉思一会：本门现在没有合适的人选，"+RANK_D->query_rude(me)+"，你先回去吧。\n"NOR);
               me->delete_temp("in_tiaozhan");
               target->delete_temp("ask_yingzhan");
               target->delete_temp("no_move");
               target->delete_temp("yingzhan_place");
               target->add("faith",-20-random(10));
        }
}

void alternative_die (object me)
{
  object ob;
  int exp=me->query("combat_exp");
   string str;
  int i=exp_level(exp);
  string pos=get_pos();
  string ofaname,mfaname;
  string omname,mmname;
  
  me->set("kee", 1);
  me->set("sen", 1);
  me->set("eff_kee",me->query("max_kee"));
  me->set("eff_sen",me->query("max_sen"));
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
      
  message_vision ("\n$N重重地摔倒在地。\n",me);
  message_vision ("地下传来崔判官的声音：门派之争，不伤阳寿！\n",me);
  message_vision ("\n$N慢慢从地上爬将起来。\n",me);
  
  ob = me->query_temp("last_damage_from");
  if (! ob)
    return;  
  
    if(!me->query_temp("in_tiaozhan")||!ob->query_temp("in_tiaozhan"))
       return;
  ofaname=ob->query("family/family_name");
  mfaname=me->query("family/family_name");
  omname=SHILI_D->query_master(ofaname);
  mmname=SHILI_D->query_master(mfaname);
  
  i=(i-3)*5+2;

  me->add("faith",-i/2-random(i/2));
  ob->add("faith",i*4/10+random(i/2));
  SHILI_D->increase_shili(pos,ofaname,i);
  SHILI_D->decrease_shili(pos,mfaname,i);

  tell_object(ob,GRN+"你耳边传来"+omname+"的声音：果然是好样的！\n"NOR);
  tell_object(me,GRN+"你耳边传来"+mmname+"的声音：岂有此理，居然输了！\n"NOR);

  if(SHILI_D->query_family(pos)==ofaname){
        str=ofaname+"接管了对"+SHILI_D->query_chinese(pos)+"的控制权！";
        this_object()->set("short",omname+"祭台");
        CHANNEL_D->do_channel(ob,"chat",str);
  }     
  me->delete_temp("in_tiaozhan");
  ob->delete_temp("in_tiaozhan");
}

int valid_leave(object me, string dir)
{
    if(me->query_temp("in_tiaozhan"))
        return notify_fail("你还在挑战中，怎么能离开呢？\n");
    return ::valid_leave(me, dir);      
}    

