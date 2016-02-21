// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i;
	string newarg, str1, str2;
	
	if( !arg ) return notify_fail("дЦр╙лФвт╪╨х║й╡ц╢╢б╨её©\n");
	
	if( arg=="none" ) {
	me->delete("nickname");
	return 1;
	}

	while(i--) {
               	if( arg[i]<' ' ) {
                       	return notify_fail("╤т╡╩фПё╛дЦ╣дм╥он╡╩дэсц©ьжфвжт╙║ё\n");
               	}
       	}

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
	arg = replace_string(arg, "$NOR$", NOR);
       arg = replace_string(arg, "$BLINK$", BLINK);

	newarg=arg; // strip away ansi color code, then count length
	// mon 8/20/98
	while(sscanf(newarg,"%s%*sm%s",str1,str2)==3)
	            newarg=str1+str2;

	if ( (i = strlen(newarg)) > 60 )
		return notify_fail
		    ("дЦ╣д╢б╨ел╚Ё╓акё╛оКр╩╦Ж╤лр╩╣Ц╣д║╒оЛаар╩╣Ц╣д║ё\n");

	me->set("nickname", arg + NOR);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : nick <мБ╨е, ╢б╨е>
	   nick none	х║оШ
 
уБ╦Жж╦аН©иртхцдЦн╙вт╪╨х║р╩╦ЖоЛаа╣дцШ╨е╩Рм╥онё╛дЦхГ╧ШоёмШтз╢б╨ежп
й╧сц ANSI ╣д©ьжфвжт╙╦д╠Дяуи╚ё╛©иртсцртоб╣д©ьжфвж╢╝ё╨

HELP +
"$BLK$ - "BLK"╨зи╚"NOR"		$NOR$ - ╩ж╦╢уЩЁёяуи╚\n"+
"$RED$ - "RED"╨Ли╚"NOR"		$HIR$ - "HIR"аа╨Ли╚"NOR"\n"+
"$GRN$ - "GRN"бли╚"NOR"		$HIG$ - "HIG"аабли╚"NOR"\n"+
"$YEL$ - "YEL"ма╩фи╚"NOR"		$HIY$ - "HIY"╩фи╚"NOR"\n"+
"$BLU$ - "BLU"иНю╤и╚"NOR"		$HIB$ - "HIB"ю╤и╚"NOR"\n"+
"$MAG$ - "MAG"гЁвои╚"NOR"		$HIM$ - "HIM"╥ш╨Ли╚"NOR"\n"+
"$CYN$ - "CYN"ю╤бли╚"NOR"		$HIC$ - "HIC"лЛгЮи╚"NOR"\n"+
"$WHT$ - "WHT"гЁ╩ри╚"NOR"		$HIW$ - "HIW"╟ви╚"NOR"\n"+
@HELP
 
фДжпо╣мЁвт╤╞╩Атзвж╢╝н╡╤к╪ср╩╦Ж $NOR$║ё

HELP
        );
        return 1;
}
