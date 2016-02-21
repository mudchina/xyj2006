//Cracked by Roath
// chfn.c
// created by xigua@dhxyii
#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
 int email_flag,icq_flag,webpage_flag;
int main(object me, string arg)
{
        object link;
       
        if( link = me->query_temp("link_ob") ) {
        	email_flag = link->query("email")?1:0;
        	icq_flag = link->query("icq")?1:0;
        	webpage_flag = link->query("webpage")?1:0;
        	if(email_flag ==0) link->set("email","");
        	if(icq_flag ==0) link->set("icq","");
        	if(webpage_flag ==0) link->set("webpage","");
                write("您的电子邮件"+(email_flag?(" [" + link->query("email") + "]："):"："));
                input_to("get_email", link);
                return 1;
        }
        return 0;
}
string rp_color(string arg)
{
     if (!arg) return "";
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$BLINK$", BLINK);
        arg = replace_string(arg, "$NOR$", NOR);
        return arg+NOR;
}

void get_email(string new_email, object link)
{
        if( new_email != ""&&strlen(new_email) < 50)
                link->set("email", new_email);
        write("您的个人主页"+(webpage_flag?(" [" + link->query("webpage") + "]："):"："));
        input_to("get_webpage", link);
}
void get_webpage(string new_webpage, object link)
{
        if( new_webpage != ""&&strlen(new_webpage) < 300)
                link->set("webpage", new_webpage);

        write("您的ICQ/OICQ"+(email_flag?(" [" + link->query("icq") + "]："):"："));
         input_to("get_icq", link);
}
void get_icq(string new_icq, object link)
{
        if( new_icq != ""&&strlen(new_icq) < 10)
                link->set("icq", new_icq);

        write("你的自我介绍(finger时显示)：\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
}
void get_profile(object link,string str)
{
        str=rp_color(str);
        if(strlen(str) > 5000)
        {
         write("介绍文字过多，请重新设定。\n\n");
         write("您的自我介绍: (finger时显示)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_profile", link:));
        }
         else {
        link->set("profile", str);
        write("您的签名格式: (post时用)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
        }
}

void get_signature(object link, string str)
{
         if( strlen(str) > 1400 )
         {
                write("签名格式太长！请重新设定　\n\n");
                write("您的签名格式: (post时用)\n");
        link->query_temp("body_ob")->edit((: call_other, __FILE__, "get_signature", link :));
        }
        else{
                str=rp_color(str);
                link->set("signature", str);
                 write("所作的修改"HIR" save "NOR"后才有效。　\n");
        }
       
}

int help(object me)
{
write(@HELP
指令格式 : chfn

用途 : 用来修改你的个人资料。
用法 ：系统将会提示你输入:
       电子邮件地址：  （你的e-mail,如果无需修改，则回车跳过）
       个人主页：      （你的个人主页网址，如果无需修改，则回车跳过)
       OICQ/ICQ号码：  （你的ICQ或则OICQ号码，如果没有可以去申请一个）
                              (www.icq.com / www.tencent.com)
       你的自我介绍：  （finger 时看到）
       你的个性化签名：（post 时用）
设置完毕后，一定要 save 才能起作用。
如果想让别人看见你的信息，你还需要：
1. set pub_email 1    →允许其他玩家察看你的电子邮件地址
2. set pub_webpage 1  →允许其他玩家察看你的个人主页地址
3. set pub_icq 1      →允许其他玩家察看你的icq/oicq地址
HELP
     );
     return 1;
}


