// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.
// modified by vikee for xlqy on 2000.11
#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"

mapping channels = ([
        "sys":  ([      "msg_speak": HIG "【系统】%s：%s\n" NOR, "wiz_only": 1 ]),
        "wiz":  ([      "msg_speak": HIY "【巫师】%s：%s\n" NOR,
                                "msg_emote": HIY "【巫师】%s\n" NOR,
                                "wiz_only": 1
                        ]),
"gwiz":	([	"msg_speak": HIG "【网际巫师】%s：%s\n" NOR,
				"msg_emote": HIG "【网际巫师】%s\n" NOR,
                                "wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
                                "filter": 1,
                                "intermud_emote": 1 ]),
        "xyj":  ([      "msg_speak": HIR "【西游记2006】%s：%s\n" NOR,
                                "msg_emote": HIR "【西游记2006】%s\n" NOR,
                                "intermud": GCHANNEL, "channel": "xyj",
                                "filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
"es":	([	"msg_speak": HIR "【千里传音】%s：%s\n" NOR,
				"msg_emote": HIR "【千里传音】%s\n" NOR,

                                "intermud": GCHANNEL, "channel": "es",
                                "filter": 1 ]), //keep the channel name
                                //as "es" to be compatible with other
                                //ES2 type muds.
        "sldh": ([      "msg_speak": HIC "【水陆大会】%s：%s\n" NOR,
                                "msg_emote": HIC "【水陆大会】%s\n" NOR,
                         ]),


        "chat": ([      "msg_speak": HIC "【太平盛世】%s：%s\n" NOR,
                                "msg_emote": HIC "【太平盛世】%s\n" NOR,
                         ]),
        "rumor":([      "msg_speak": HIM "【长安夜话】%s：%s\n" NOR,
                                "msg_emote": HIM "【长安夜话】%s\n" NOR,
                        "msg_color":NOR+HIM,
                                "anonymous": "某人"
                        ]),
        "music":([      "msg_speak": MAG "【心笙乐府】%s唱着：%s\n" NOR,
                         ]),
	     "cs":([  "msg_speak": HIW "【CS小组】%s：%s\n" NOR,
            "msg_emote": HIW "【CS小组】%s" NOR,
            "msg_color": HIY,
            "cs_only": 1 ]), 
            
    "club":([  "msg_speak": HIW "【帮派】%s：%s\n" NOR,
            "msg_emote": HIW "【帮派】%s" NOR,
            "msg_color": HIW,
            "party_only": 1 ]), 
         "party":([  "msg_speak": HIY "【门派】"+HIB"%s: %s\n" NOR,
                          "msg_emote": HIY "【门派】"+HIB"%s" NOR,
   "msg_color": NOR+HIY,
            "menpai_only": 1 ]),
]);
string party;
string cs,faction;
string menpai;
void add_rumor(object me,string msg);
int can_chat( string sArg ) //允许说话?
  {
           if ( strsrch( sArg , ".") != -1  || strsrch( sArg , ".")!= -1 )
                    return 0 ;
           else

                return 1 ;
}
void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
        this_object()->set("rumor_point",0);
}

varargs int do_channel(object me, string verb, string arg, int emote,
        int allow_chat)
{
        object *ob;
        string *tuned_ch, who, arg1;
        int time,count,count1,last_chat,len;

        // Check if this is a channel emote.
        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
                emote = 1;
                verb = verb[0..<2];
        }
        
        // mon 10/29/98
        // ignore too long messages to reduce flooding.
        if(arg && strlen(arg)>240) return 0;

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;

           if ( !wizardp(me) && arg && !can_chat(arg) ) // for ban chat
                return 0 ;


        if( userp(me) && !allow_chat ) {
                if(channels[verb]["wiz_only"] && !wizardp(me) )
                        return 0;
        if(channels[verb]["party_only"] && !me->query("club"))
                return notify_fail("你还是先加入一个帮派再说吧。\n");

        if (channels[verb]["party_only"]) {
                party = me->query("club");
                channels[verb]["msg_speak"] = HIY "【"+party+"】%s：%s\n" NOR;

        channels[verb]["msg_emote"] = HIY "【"+party+"】%s\n" NOR;

        }

		if(channels[verb]["cs_only"] && !me->query_temp("pkgame"))
                return notify_fail("你现在没有参加ＣＳ大赛。\n");
                
        if (channels[verb]["cs_only"]) {
                cs = me->query_temp("pkgame");
                if (cs =="t")
                	faction = HIR"纵火犯"HIY;
                else
                	faction = HIC"大侠"HIY;
                channels[verb]["msg_speak"] = HIY "【"+faction+"】%s：%s\n" NOR;
        	channels[verb]["msg_emote"] = HIY "【"+faction+"】%s\n" NOR;
        }
         
         if (channels[verb]["menpai_only"] && !me->query("family/family_name"))
              return notify_fail("你是哪个门派的。\n");
          
          if (channels[verb]["menpai_only"]) {
       menpai = me->query("family/family_name");
channels[verb]["msg_speak"] = HIG "【"HIR+menpai+HIG"】%s：%s\n" NOR;
channels[verb]["msg_emote"] = HIG "【"HIR+menpai+HIG"】%s\n" NOR;
}
    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("对不起，这个频道不支持 emote 。\n");
        return 1;
    }

                //temporary block chat flooding.
                time=time();
                if(me->query("channel/chat_block") &&
                  (time-me->query("channel/chat_block"))<0 )
                   return notify_fail("你的交谈频道被暂时关闭了。\n");
              
                count=me->query("channel/chat_count");
                // if the channel arg contains too many lines,
                // then count more than once. -- mon 8/16/98
                count1=sizeof(explode(" "+arg,"\n"))/3+1;
                // if arg too long, also counts more.
                count1+=sizeof(arg)/200;
                count+=count1;
                last_chat=me->query("channel/last_chat");
                if (count>2) {
                  count=0;
                  me->set("channel/last_chat",time);
                  if (time==last_chat || count1>2) {
                    me->set("channel/chat_block",time+180);
                    return notify_fail("因为一次讲话太多，你的交谈频道被暂时关闭了。\n");
                  }
                }
                me->set("channel/chat_count",count);

                if( arg==(string)me->query_temp("last_channel_msg") )
                        return notify_fail("用交谈频道说话请不要重复相同的讯息。\n");

                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );

                // Support of channel emote
                if( emote && !channels[verb]["intermud_emote"]) {
                        string vb, emote_arg;

                        if( nullp(arg) ) return 0;
                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                                vb = arg;
                                emote_arg = "";
                        }
                if( channels[verb]["anonymous"] )
                           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
                else {
                   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
                        int age=me->query("mud_age");
                        // prevent login  newbie to flood channels.
                        if(!wizardp(me)) {
                            if(age<3600) return notify_fail(
                                    "你现在还不能使用这个频道。\n");
                            else if(age<86400) {
                                if((int)me->query("sen")<30) return 
                                    notify_fail
                                        ("你现在精神不足，不能使用这个频道。\n");
                                me->add("sen",-5);
                            }
                        }

                REMOTE_Q->send_remote_q(site, verb, me->query("id"), id, vb);
                write("网路讯息已送出，请稍候。\n");

                return 1;
                      }
                   }
                }

                if( !arg ) return 0;
                }
        }

        // Make the identity of speaker.

        if( channels[verb]["anonymous"] ) {
                who = channels[verb]["anonymous"];
                if (userp(me)) {
                    if((int)me->query("sen")<50) return
                        notify_fail("你已经没有精神散布谣言了。\n");
                    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
                    sprintf("谣言：%s(%s)。", me->name(1),me->query("id")));
                  
                }
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
                who = me->query("name");
                if(me->query("id")) 
                  who=who+"(" + capitalize(me->query("id")) + ")";
             }

        // Ok, now send the message to those people listening us.

        ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
        if( !arg ) arg = "．．．";

        len=strlen(arg);
        while(len>1 && arg[len-1]=='\n')
            arg=arg[0..((len--)-2)];
        //remove excessive return at the end. by mon 9/20/97

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

        if( emote ) {
                // Support of old behavier of intermud emote.
                if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
        }

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
            int age=me->query("mud_age");

            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

            // prevent login  newbie to flood channels.
            if(!wizardp(me)) {
              if(age<3600) return notify_fail(
                    "你现在还不能使用这个频道。\n");
              else if(age<86400) {
                if((int)me->query("sen")<30) return 
                    notify_fail
                        ("你现在精神不足，不能使用这个频道。\n");
                me->add("sen",-5);
              }
            }
          }
          channels[verb]["intermud"]->send_msg(
                channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

        if( emote ) {
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
        } else
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

        if( userp(me) ) 
        {
                me->set_temp("last_channel_msg", arg);
        }
        if( channels[verb]["anonymous"] ) add_rumor(me,arg); 
        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;

        if( ch["wiz_only"] ) return wizardp(ppl);
        //as followed add by vikee,only belong to the party & wizard can see these message
        if (ch["party_only"])
                return (wizardp(ppl)
                && (!ppl->query("env/party") || ppl->query("env/party")==party))
                || party == ppl->query("club"); 
         //as followed add by yesi,only belong to the menpai & wizard can see these message
         if (ch["menpai_only"])
                return (wizardp(ppl)
                || ppl->query("family/family_name")==menpai); 
		 if (ch["cs_only"])
                return (wizardp(ppl)
                || ppl->query_temp("pkgame")==cs); 
        return 1;
}

void register_relay_channel(string channel)
{
        object ob;

        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}

void add_rumor(object me,string msg)
{
        object ob=this_object();
        string msg_id;
        int i;
        int detect_chance;
        int rumor_point=ob->query("rumor_point");
        rumor_point++;
        if (rumor_point>10) rumor_point-=10;
        i=sizeof(msg_id);
        msg_id="rumor_msg_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=rumor_point;
        ob->set(msg_id,msg);
        msg_id="rumor_id_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=rumor_point;
        ob->set("rumor_point",rumor_point);
        detect_chance=31-(int)(me->query("daoxing")/33333);
        if (!userp(me) || wizardp(me) || random(100)>detect_chance)
         {
           ob->set(msg_id,"none");
           return;
         }
        ob->set(msg_id,me->query("name")+"("+me->query("id")+")");
        return;                 
}

string query_rumor_msg(int num)
{
        string msg_id;
        string msg;
        int i;
        msg_id="rumor_msg_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=num;
        return this_object()->query(msg_id);
}
string query_rumor_id(int num)
{
        string msg_id;
        string msg;
        int i;
        msg_id="rumor_id_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=num;
        return this_object()->query(msg_id);
}
