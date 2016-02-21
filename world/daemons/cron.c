#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <obstacle.h>
#define FILE "/u/bmw/npc/pker.c"

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void emery();

void create()
{
        seteuid( ROOT_UID );
        init_cron();
}

int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}
void init_cron()
{
        mixed *local;
        local = localtime(time());
        if ( !((local[1])%30)) autosave();
        if (random(5))TASK_D->init_dynamic_quest();
        else TASK_D->init_dynamic_quest(1);
        call_out("init_cron", 120);  
}

void autosave()
{
 object *user ;
 int i;
        user = users();
        message("chat", HIY "自动更新幻想西天TASK任务。\n"NOR, users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
}

void emery()
{
        object me,emery,*user;
object xu=load_object("/d/huanggong/npc/dachen2");

        int i,x,m,n;
        string *dirs;

        dirs = ({"/d/gao/","/d/jz/", "/d/changan/","/d/eastway/","/d/kaifeng/",
                });

         user= users();
         i = random(sizeof(dirs));

         n =  (int)(sizeof(users())/7+random(sizeof(users())/7)+1);
       message("system",HIW "【黑暗宝马】:"+HIR+"杀手们听令！血洗那个所谓宝马真身所创造的幻想世界！\n"NOR, users());
        for(x=0;x<n;x++)
        {
 emery=new("/u/bmw/npc/pker.c");
        emery->random_go(me,dirs,i);
        }
message("system",GRN"【宝马真身】：现共有"+chinese_number(n)+"个杀手正在"+TASK_D->query_city(environment(find_living("guai shou")))+"作乱！\n"NOR,users());
        xu->set("mark",time());
        remove_call_out("check_guaiwu");
        call_out("check_guaiwu",10,xu);

        for(m=0;m<sizeof(user);m++)
        {
        user[i]->set("kill_guaishou",1);
        }
}
       
void check_guaiwu(object xu)
{

        if( time() - xu->query("mark") > 10*60 )
        {
        remove_call_out("end");
        call_out("end",3);
        return;     
         }

      if(sizeof(filter_array(children(FILE),(:clonep:))) > 1)
       {      
     message("system",GRN"【宝马真身】：大家加油啊，杀手还没有杀完！\n"NOR,users());
        remove_call_out("check_guaiwu");
        call_out("check_guaiwu",20,xu);
        }
        else 
        {
  message("system",GRN"【宝马真身】：恭喜各位杀死所有的杀手，感谢大家保护了幻想世界！！\n",users());
  remove_call_out("reward");
        call_out("reward",3);
       }

}

void end()
{
        object *user;

        object tang=find_living("tang taizong");
        int i;
        user=users();

        if(sizeof(filter_array(children(FILE),(:clonep:)))>=1)
        {
message("system",HIM"【谣言】某人：幻想西天的世界被杀手们蹂躏了！\n"NOR,users());
        for(i=0;i<sizeof(user);i++)
         {
                user[i]->delete("kill_guaishou");
                user[i]->query("office_number")? user[i]->add("office_number",-1): user[i]->add("office_number",0);

         }
 //       if( tang )
 //       destruct(tang);
        }
}






