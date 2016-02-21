//Cracked by Roath
#include <ansi.h>
#include <command.h>
#include <questd.h>
#pragma save_binary

string *quests;
string *roomlines;
string daoxing(int dx);
mapping maps;

varargs void init_dynamic_quest(int hard);
varargs int spread_quest(string one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
int locate_quest(object me,string arg);
string dyn_quest_list();
string query_city(object loc);

void create()
{
   string file,dir,name;
   string* buf1;
   int i,size;
        
   maps=([]);
   file = read_file("/d/obj/quest/dynamic_location");
   roomlines = explode(file,"\n");
   file = read_file("/d/obj/quest/dynamic_quest");      
   quests = explode(file,"\n");
   file = read_file("/cmds/std/find.map");
   buf1 = explode(file,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
   CRON_D->set_last_hard_dis();
   init_dynamic_quest(1);
seteuid(getuid());
}

int quest_reward(object me, object who,object quest_item)
{
        int exp,pot,score;

        if(who->query("id")!= quest_item->query("owner_id")) return 0;
        score=me->query_temp("dynamic_find")+1;        
        exp =250+random(300*(10+score)/10);
        pot = exp/8;
        me->add("daoxing",exp);
        me->add("potential",pot);
        me->add("task_job",1);
//        tell_object(me,"Äã±»½±ÀøÁË£º\n" +
//        COMBAT_D->chinese_daoxing(exp) + "µÀÐÐ\n"+
//            chinese_number(pot) + "µãÇ±ÄÜ\n");
  tell_object(me, sprintf("Äã»ñµÃÁË"HIR"%s"NOR"µÄµÀÐÐ ,"HIY"%s"NOR"µãÇ±ÄÜ£¡\n"NOR, daoxing(exp),chinese_number(pot)) );
CHANNEL_D->do_channel(this_object(),"rumor",sprintf(HIG+me->name()+NOR"½«Ñ°µ½µÄ"HIW+quest_item->name()+NOR"ËÍ¸ø"+who->name()+"»ñµÃ"HIR+daoxing(exp)+NOR"µÄµÀÐÐ£¬"HIY+chinese_number(pot)+NOR"µãÇ±ÄÜ\n"));

	log_file("static/TASK","["+ctime(time())+"] "
	       +sprintf("%d. %s(%s)½«Ñ°µ½µÄ"
              HIW+quest_item->name()+NOR"ËÍ¸ø"+who->name()
	      +"»ñµÃ%dµÄµÀÐÐºÍ%dµãÇ±ÄÜ.\n",
	      me->query_temp("dynamic_find"),
              me->query("name"),me->query("id"),exp,pot));


                        if(score==10){
            me->delete_temp("dynamic_find");
            me->add("combat_exp",500);
            tell_object(me,"ÄãÕæÐÐ£¬ÄãµÃµ½ÁË"+chinese_number(500) + "µãÎäÑ§¾­ÑéµÄ¸½¼Ó½±Àø£¡\n");        
        }
        else me->set_temp("dynamic_find",score);
        
        return 1;
}

varargs void init_dynamic_quest(int hard)
{
        int i;
        for( i=0; i < sizeof(quests)/2; i++)
                spread_quest(quests[i*2],hard);
}
string find_location()
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return "d/city/center";

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) ) return "/d/city/center";
        for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {
                  if (  !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                   continue;
                   return dirs[i]+"/"+file[j][0];
               }
           }
        }

}
varargs int spread_quest(string quest, int hard)
{
        object obj0,obj1,obj2,obj3;
        object cur_obj;
        object next_obj;
        object tar;
        object *inv;
        object *target=({});
        int i;
        string location;
        if(already_spreaded(quest,hard)) return 0;
        reset_eval_cost();
        if (random(2)) 
          location = roomlines[random(sizeof(roomlines))];
	else 
	  location=find_location();
        obj0=find_object(location);
        if(obj0)
        obj0->reset();
        else
        obj0=load_object(location);
        cur_obj =obj0;
        if(cur_obj)
        {
        inv = all_inventory(cur_obj);
        for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->is_character() && !userp(inv[i]))
        target += ({ inv[i] });
        if(inv[i]->is_container()) target += ({ inv[i] });
                }
        }
        if(sizeof(target)) cur_obj = target[random(sizeof(target))];
        if(cur_obj)
        {
        tar = new(quest);
        tar->set("value",0);
        tar->move(cur_obj);             
        }
return 1;
}

string dyn_quest_list()
{
        string output;
        object item;
        int i;
        
   output="";
        for( i=0; i < sizeof(quests)/2; i++)
        {
        if(!objectp(item= find_object(quests[i*2])))
            item = load_object(quests[i*2]);
        if(already_spreaded(quests[i*2]))
            if(random(2))output += sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",item->query("owner_name"),item->query("name"),item->query("id"));
            else output=sprintf(HIG"%10s"NOR"µÄ"HIW"%10s"NOR"£¨%s£©\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
        else
            if(random(2))output += sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£© [1;31m¡¾  [32mÒÑÍê³É[31m ¡¿[m\n",item->query("owner_name"),item->query("name"),item->query("id"));
            else output=sprintf(HIG"%10s"NOR"µÄ"HIY"%10s"NOR"£¨%s£©[1;31m ¡¾ [32m ÒÑÍê³É[31m  ¡¿[m\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
        }
        output ="[1;32m¡ù[33mÎ÷ÓÎ¼Ç2006[31mÊ¹Ãü°ñ[32m¡ù[m\n"+
                "©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥\n"+output+
                "©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥\n\n";

        return output;
}

varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;
        if(!str) return 0;
        if(hard)
        {
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                { ob_list[i]->move(VOID_OB);
                 destruct(ob_list[i]);
                }
        }
        return 0;
        }
        else
        {
        if(!str) return 0;
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                        return 1;
        }
        return 0;
        }
}

object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("exits") || userp(ob) ) return ob;
        else ob=environment(ob);
        }
        return ob;
}

int locate_quest(object me, string arg)
{
    object loc,ob;
    string qloc,msg,quest;
    string* exlst;
    object* itemlist;
    mapping exits;
    int index,i;
    
if( ! arg)
return notify_fail("locate <ÎïÆ·id>\n");
    if(present(arg,me))
    {
        tell_object(me,"Ëü²»ÕýÔÚÄãµÄÉíÉÏÂð£¿\n");
	return 0;
    }
    
    if((index=member_array(arg,quests,0))>0)quest=quests[index-1];
    else return 1;
    
    if(!already_spreaded(quest)){
        tell_object(me,HIW"Ê¹Ãü°ñ"NOR"Ò»µã·´Ó¦Ò²Ã»ÓÐ£¬·Â·ðËü¸ù±¾²»´æÔÚÕâ¸öÊÀ½çÉÏ¡£\n");
        return 0;
    }

    itemlist = children(quest);
    for(index=0;index<sizeof(itemlist);index++){
      if(objectp(loc=find_env(itemlist[index]))){
           if (userp(loc))
	    {
                tell_object(me,HIC+itemlist[index]->query("name")+NOR+"ÕýÔÚ"+
                 loc->query("name")+"("+loc->query("id")+")µÄÉíÉÏ.\n");
		return 1;
	    }
          qloc = query_city(loc);
          exits=loc->query("exits");
          exlst=keys(exits);
          msg=HIW+itemlist[index]->query("name")+NOR"·Â·ðÔÚ"HIG+qloc+
              NOR"Ò»´¦ÓÐ";
          if(sizeof(exlst)){
                for(i=0;i<sizeof(exlst)-1;i++)msg+=exlst[i]+"¡¢";
                msg+=exlst[sizeof(exlst)-1]+"³ö¿ÚµÄµØ·½¡£\n";
                tell_object(me,HIW"Ê¹Ãü°ñ"NOR"ÏÔÊ¾£º\n"+msg);
                return 1;
          }
   
      }
    }   
    tell_object(me,HIW"Ê¹Ãü°ñ"NOR"Ò»µã·´Ó¦Ò²Ã»ÓÐ¡£\n");
    return 1;
}

string query_city(object loc)
{
        string filename,filename1;
        int len;
        
        filename=file_name(loc);
        len=strlen(filename);
        if(len<2) return "???";

        len--;
        while(filename[len]!='/' && len>0) {
          len--;
        }
        if(len<2) return "???";

        filename1=filename[1..(len-1)];
        return maps[filename1]; 
}
string daoxing(int dx)
{
	
	int day,hour;
	day = (dx) / 4;
	hour = (dx  - day * 4) * 3; 
	return day?(chinese_number(day)+"Ìì"):""+hour?(chinese_number(hour)+"Ê±³½"):"";
}
