// aliasd.c

mapping global_alias = ([
	"l":	"look",
	"n":	"go north",
	"e":	"go east",
	"w":	"go west",
	"s":	"go south",
	"nu":	"go northup",
	"eu":	"go eastup",
	"wu":	"go westup",
	"su":	"go southup",
	"nd":	"go northdown",
	"ed":	"go eastdown",
	"wd":	"go westdown",
	"sd":	"go southdown",
	"ne":	"go northeast",
	"se":	"go southeast",
	"nw":	"go northwest",
	"sw":	"go southwest",
	"u":	"go up",
	"d":	"go down",
	"i":	"inventory",
	"tt":	"team talk",
        "tt*":   "team talk*",
	"bai":	"apprentice",
//	"beifen":	"backup",
//	"biecheng":	"nick",
//	"bieming": "alias",
	"cha":	"check",
	"chuan":	"wear",
	"cun":	"save",
	"dazuo":	"exercise",
//	"diu":	"drop",
//	"dou":		"fight",
	"du":	"study",
//	"eryu":	"whisper",
//	"fang":	"put",
	"fangqi": "abandon",
	"fangxia":	"unwield",
	"fei":		"fly",
//	"gaosu":	"tell",
//	"gei":	"give",
	"gen":	"follow",
	"guan":	"close",
//	"guancha":	"observe",
	"huida":	"reply",
//	"jia":	"marry",
	"jiali":	"enforce",
	"jianju": "accuse",
//	"jieshou": "accept",
	"jifa":	"enable",
	"jineng":	"skills",
	"kai":	"open",
	"kaichu":	"expell",
//	"kan":	"look",
	"lian":	"practice",
//	"mai":		"buy",
	"miaoshu":	"describe",
	"mingsi":	"meditate",
//	"na":	"get",
	"qiuhun":	"propose",
	"sha":	"kill",
	"shou":	"recruit",
//	"shui":	"sleep",
	"shuo":	"say",
	"tou":	"steal",
	"touxian":	"title",
	"touxiang":	"surrender",
	"tuo": "remove",
//	"wen":	"ask",
	"xue":	"learn",
	"yaoqing":	"invite",
	"zhao":		"find",
	"zhuangbei":	"wield",
//	"zisha": "suicide"
]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}
