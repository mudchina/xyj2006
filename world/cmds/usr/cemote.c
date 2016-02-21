// function:    display emote
// update by:   ken@mud.szptt.net.cn
// update time: 1998-03-13

#include "/doc/help.h"

inherit F_CLEAN_UP;
inherit EMOTE_D;

int main(object me, string arg)
{
        mapping point;
        string *emotes, msg, str;
        int i;

        if( !arg || lower_case(arg) == "all") {
                emotes = sort_array(query_all_emote(), 1);
                if( !emotes ) {
                        msg = MUD_NAME+"当前没有任何 emote。\n";
                        return notify_fail(msg);
                }
        }
        else {
                point = EMOTE_D->query_emote(arg);
                if( !point["updated"] ) {
                        msg = sprintf("%s当前没有 %s 这个 emote。\n",MUD_NAME,arg);
                        return notify_fail(msg);
                }
        }

        msg = "\n";



        if( ! arg || lower_case(arg) == "all") {
                for(i=0; i<sizeof(emotes); i++) {
                        if(emote[emotes[i]]["others_target"])
                                str = emote[emotes[i]]["others_target"];
                        else {
                                if(emote[emotes[i]]["others"])
                                        str = emote[emotes[i]]["others"];
                                else str = emote[emotes[i]]["others_self"];
                                }

                        if(!str)  continue;

                        str = replace_string(str, "$n", "(对方)");
                        str = replace_string(str, "$N", me->name(1));
                        str = replace_string(str, "$P", "你");
                        str = replace_string(str, "$p", "(他/她)");
                        str = replace_string(str, "$S", RANK_D->query_self(me));
                        str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                        str = replace_string(str, "$R", "(对方的尊称)");
                        str = replace_string(str, "$r", "(对方的辱称)");
                        str = replace_string(str, "$C", "(自己的呢称)");
                        str = replace_string(str, "$c", "(对方的呢称)");

                        msg += sprintf("名称：%s\n内容：%s\n", emotes[i],str,);
                }
                msg += sprintf("%s 目前共有 %d 个 emote。\n",MUD_NAME,i);
        }
        else {
                str = point["target"];
                str = replace_string(str, "$n", "你");
                str = replace_string(str, "$p", "你");
                str = replace_string(str, "$R", "(你的尊称)");
                str = replace_string(str, "$r", "(你的辱称)");


                msg += sprintf("\nemote 名称：%s\n\n"
                        "自己看见：\n%s%s%s\n\n"
                        "对方看见：\n%s\n"
                        "其他人看见：\n%s%s%s\n",
                        arg,
                        point["myself"], point["myself_self"],point["myself_target"],
                        str,
                        point["others_self"],
                        point["others"],
                        point["others_target"] );

                        msg = replace_string(msg, "$n", "(对方)");
                        msg = replace_string(msg, "$N", me->name(1));
                        msg = replace_string(msg, "$P", "你");
                        msg = replace_string(msg, "$p", "(他/她)");
                        msg = replace_string(msg, "$S", RANK_D->query_self(me));
                        msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                        msg = replace_string(msg, "$R", "(对方的尊称)");
                        msg = replace_string(msg, "$r", "(对方的辱称)");
                        msg = replace_string(msg, "$C", "(自己的呢称)");
                        msg = replace_string(msg, "$c", "(对方的呢称)");

        }
        me->start_more(msg);

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : chkemote, chkemote [emote名]。

这个指令可以列出目前所能使用的 emote 或者单独列出
某个 emote 的内容。

HELP
        );


return 1;
}


