#include <ansi.h>
// Edit By Canoe
// 智能化
inherit NPC;
#define BS "/d/city/prison"  //受惩罚的玩家被送往的地点，为了避免玩家利用此NPC作弊，比如死
                             //后说脏话被送到阳间从而达到隐身的目的，所以，此地点最好在地狱。 
                             //自造房间：拔舌地狱
#define TJ "/d/city/kezhan"  //铁面判官办公地点，为了防止他心跳停止，丧失功能，此地点最好是经常有玩家经过的地方，中心广场最合适.
string *msg_d = ({
                      "他妈的","你妈的","傻B","我操","操你","和你妈睡",
                    "操！","操!","fuck","FUCK","Fuck","婊子","f~u~c~k",
                    "你奶奶的","和你妈做爱","她妈的","你爷爷的",
                    "放屁","滚蛋","放狗屁","放你妈的屁","tmd",
                   "wo cao","fUck","fuCk","fucK","Tmd","tMd",
                    "tmD","Tmmd","tMmd","tmMd","tmmD","Tnnd","tNnd",
                    "tnNd","tnnD","SB","干你妈","干你娘",
                    "干你姐","干你老娘","干你妈","干你老妈","干你妹","干你小妹",
                    "Wo kao","wO kao","wo Kao","wo kAo","wo kaO",
                   "Wokao","wOkao","woKao","wokAo","wokaO",
                    "cAo","caO","Kao","kAo","kaO","日你老妈","干你老母",
                    "干你哥","干你弟","sHit","shIt","shiT","狗巫师",
                    "TMD","tmmd","TMMD","tnnd","TNND","wokao",
                    "wo kao","日死你","干死你","干你娘","他妈妈的","狗屁巫师",
                    "操你","狗屁wiz","狗wiz","破wiz","破巫师","日死你","shit",
                      "SHIT","Shit","wocao","wo cao","强奸你",
                      
                      });

void punish(object ob,string msg);

void create()
{
    set_name(HIR"环境判官"NOR, ({"pan guan", "panguan", "guan"}));
        set("gender", "男性" );
        set("age", 35);
  set("title","铁面无私");
        set("per", 5);

 set("long", HIR"无人不知的铁面判官，专为维护本站良好游戏环境而设。\n"NOR);
        set("combat_exp", 5000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 800);
       set_skill("dodge", 800);
       set_skill("parry", 800);
       set_skill("blade", 800); 
       set_skill("force", 800); 
       set_skill("literate", 800);   
//     set("no_shown", 1); 
       set("max_force", 40000);   
       set("force", 40000);
       set("max_mana", 40000);
       set("mana", 40000);
       set("max_kee", 40000);
       setup();  

//以下是被监控的频道，各MUD不同。
       if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");
 if( clonep() ) CHANNEL_D->register_relay_channel("qq");
       if( clonep() ) CHANNEL_D->register_relay_channel("es");
       if( clonep() ) CHANNEL_D->register_relay_channel("xyj");
       if( clonep() ) CHANNEL_D->register_relay_channel("sldh");
//   if( clonep() ) CHANNEL_D->register_relay_channel("baby");
}  

void relay_channel(object ob, string channel, string msg) 
 {
          int i;
          if( !userp(ob) || (channel == "sys") ) 
                  return; //npc与系统信息不受此限制 
         if(wizardp(ob)) return;//wizard不受限制
          for(i=0; i<sizeof(msg_d); i++) //逐条检验
         {
              if( strsrch(msg, msg_d[i]) >= 0) //搜索(在频道的话中)
                    {
                     ob->add_temp("maren",1);  
                       if(ob->query_temp("maren")>1||time()-ob->query("last_maren") <60)
                      {
                      ob->delete_temp("maren");
call_out("punish0",0,ob);
                      }
else tell_object(ob,HIW"你突然浑身一抖,原来是不小心用脏字!\n你被盯上了,小心被关哦!\n"NOR);
    ob->set("last_maren", time());   
                     return;  
                    }  
          }
  }
void punish0(object ob)
{
         ob->start_busy(30);
command("chat* 忽听铁面判官一声怒喝："+ob->query("name")+"骂人了，小的们,打入地狱!");
           call_out("punish", 30, ob);
        }

void punish(object ob,string msg)
  {
          object *inv;
          int i;
   if(ob->is_fighting()||ob->is_busy())
    {
    call_out("punish", 1, ob); return; }
         message_vision(HIC"空中飞下一根绳子，一下就套住$N的脖子。\n"NOR+CYN"$N伸长舌头、翻"+
   "着白眼地被拖走了。\n"NOR, ob);
          ob->move("/d/city/prison");
          ob->set("channel/chat_block",time()+900);
          message_vision(CYN"环境判官狂笑道:小的们,大刑伺候!\n"NOR, ob);
          message_vision(CYN"说着，绳子一松，$N被扔在地上。\n"NOR, ob);
          inv = all_inventory(ob);
          for(i=0; i<sizeof(inv); i++) 
              {
                         destruct(inv[i]);
               }
          ob->be_ghost(1);
          ob->add("gab_word",1);  //第一次说脏话只是警告。
       ob->apply_condition("maren",5+(int)ob->query("gab_word")*5);
          return;
          } 
