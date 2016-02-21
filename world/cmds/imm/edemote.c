// edemote.c
// modified by none 96/12/1
// modified by yyzz 96/12/11

inherit F_CLEAN_UP;

int in_use;
string *emindex=
    ({"myself","others","myself_self","others_self",
    "myself_target","target","others_target"}); 
string *emexplain=
    ({
       "不指定对象使用这个 emote 时，你自己看到的讯息：",
       "不指定对象使用这个 emote 时，其他人看到的讯息：",
       "对自己使用这个 emote 时，自己看到的讯息：",
       "对自己使用这个 emote 时，其他人看到的讯息：",
       "对别人使用这个 emote 时，自己看到的讯息：",
       "对别人使用这个 emote 时，使用对象看到的讯息：",
       "对别人使用这个 emote 时，除你自己和使用对象外，其他人看到 的讯息："
    });
int main(object me, string arg)
{
  mapping emote;
  mapping emote2;

  if( !arg ) 
    return notify_fail("你要编辑什么 emote？\n");

  if( sscanf(arg, "-d %s", arg) ) 
  {
    log_file("FILES", sprintf("%s(%s) delete emote %s on %s.\n", 
        me->name(1), geteuid(me), arg, ctime(time()) ) );
    write("删除 emote：" + arg + "\n");
    EMOTE_D->delete_emote(arg);
    return 1;
  }

  if( sscanf(arg, "-e %s", arg) ) 
  {
     int i;
     log_file("FILES", sprintf("%s(%s) modify emote %s on %s.\n", 
         me->name(1), geteuid(me), arg, ctime(time()) ) );
     emote = EMOTE_D->query_emote(arg);
     emote = (["updated":geteuid(me)]);

     write("编辑 emote：" + arg + "\n");
     write("讯息可以有好几行，用 . 表示结束。\n");
     write("用 s 表示此项输入。\n");
     write("用 a 表示放弃此 emote 输入□n");
     write("讯息中可使用的参数有以下几种：\n");
     write("  $N  自己的名字。\n");
     write("  $n  使用对象的名字。\n");
     write("  $P  自己的人称代名词，如你、□、他、她、它、它。\n");
     write("  $p  使用对象的人称代名词，如你、□、他、她、它、它。\n");
     write("  $S  对自己的称呼。\n");
     write("  $s  对自己的粗鲁称呼。\n");
     write("  $C  别人对自己的尊称。\n");
     write("  $c  别人对自己的粗鲁称呼。\n");
     write("  $R  对别人的尊称。\n");
     write("  $r  对别人的粗鲁称呼。\n");
     write("────────────────────────────────────\n");
     i=0;
     emote2 = EMOTE_D->query_emote(arg);
     write(emexplain[0]+"\n");
     printf("上次修改: %s->",emote2[emindex[i]]);
     input_to("get_msg",emote,arg,i);
     return 1;
  }
  emote = EMOTE_D->query_emote(arg);
  printf("上次修改：%s\n", emote["updated"]);
  printf("─────────────\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
  emote["myself"], emote["others"], emote["myself_self"],
     emote["others_self"], emote["myself_target"], emote["target"],
     emote["others_target"] );
  return 1;
}


int get_msg(string msg,mapping emote, string pattern,int i)
{
   mapping emote2;
   emote2 = EMOTE_D->query_emote(pattern);
   if (msg==".")
   {
     if( !undefinedp(emote[emindex[i]]) ) 
        emote[emindex[i]] += "\n";
     if(i==6)
     {
       EMOTE_D->set_emote(pattern, emote);
       write("Emote 编辑结束。\n");
       return 1;
     }
     write(emexplain[i+1]+"\n");
     printf("上次修改: %s->",emote2[emindex[i+1]]);
     input_to("get_msg", emote, pattern,i+1);
     return 1;
   }
   if (msg=="s")
   {
        emote[emindex[i]] =emote2[emindex[i]];
     if(i==6)
     {
       EMOTE_D->set_emote(pattern, emote);
       write("Emote 编辑结束。\n");
       return 1;
     }
     write(emexplain[i+1]+"\n");
     printf("上次修改: %s->",emote2[emindex[i+1]]);
     input_to("get_msg", emote, pattern,i+1);
     return 1;
   }
   if (msg=="a")
   {
     return 1;
   }
   if( !undefinedp(emote[emindex[i]]) )
     emote[emindex[i]] += msg + "\n";
   else 
     emote[emindex[i]] = msg;
   write("->");
   input_to("get_msg",emote,pattern,i);
   return 1;
}

int help(object me)
{
write(@HELP
指令格式 : edemote [-e|-d] <emote>
 
这个指令可以修改, 删除 emote 或列出其内容. 加上 -d 参数会删除
指定的 emote, -e参数编辑指定的 emote.  无参数则会列出指定 emote 的内容,
列出的顺序与编辑 emote 时相同.
 
输入 emote 讯息时有三个项目: 没有目标, 指定目标或是对自己. 若
不想有某项讯息, 则直接在空白行输入 '.' 跳过.
 
一个 emote 讯息可以有很多行, 在空白行输入 '.' 结束输入该项 emote.
在空白行输入 's' 跳过输入该项 emote.
在空白行输入 'a' 放弃输入该项 emote.
 
编辑 emote 时可以用以下的符号来表示:
 
$N : 自己的名字.
$n : 目标的名字.
$P : 自己的人称代名词.
$p : 目标的人称代名词.
$S : 对自己的称呼。
$s : 对自己的粗鲁称呼。
$C : 别人对自己的尊称。
$c : 别人对自己的粗鲁称呼。
$R : 对别人的尊称。
$r : 对别人的粗鲁称呼。
 
HELP
    );
    return 1;
}
