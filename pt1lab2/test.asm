
_test:     file format elf32-i386


Disassembly of section .text:

00001000 <main>:
   test(n+1);
//   printf("n %c\n", n);
   return n;
}
int main(int argc, char *argv[])
{
    1000:	55                   	push   %ebp
    1001:	89 e5                	mov    %esp,%ebp
    1003:	83 e4 f0             	and    $0xfffffff0,%esp
    1006:	83 ec 10             	sub    $0x10,%esp
   int pid=0;
   pid=fork();
    1009:	e8 9c 02 00 00       	call   12aa <fork>
   if(pid==0){
    100e:	85 c0                	test   %eax,%eax
    1010:	75 25                	jne    1037 <main+0x37>
//   int x=1;
//   printf(1, "address %x\n", &x);
   test(1);
    1012:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1019:	e8 32 00 00 00       	call   1050 <test>
   exec("null",0);
    101e:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
    1025:	00 
    1026:	c7 04 24 b7 17 00 00 	movl   $0x17b7,(%esp)
    102d:	e8 b8 02 00 00       	call   12ea <exec>
   exit();
    1032:	e8 7b 02 00 00       	call   12b2 <exit>
   }
   wait();
    1037:	e8 7e 02 00 00       	call   12ba <wait>
    103c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
//   test(1);
   exit();
    1040:	e8 6d 02 00 00       	call   12b2 <exit>
    1045:	66 90                	xchg   %ax,%ax
    1047:	66 90                	xchg   %ax,%ax
    1049:	66 90                	xchg   %ax,%ax
    104b:	66 90                	xchg   %ax,%ax
    104d:	66 90                	xchg   %ax,%ax
    104f:	90                   	nop

00001050 <test>:
#include "types.h"
#include "stat.h"
#include "user.h"

int test(int n)
{
    1050:	55                   	push   %ebp
    1051:	89 e5                	mov    %esp,%ebp
    1053:	53                   	push   %ebx
    1054:	83 ec 14             	sub    $0x14,%esp
    1057:	8b 5d 08             	mov    0x8(%ebp),%ebx
   if(n<100)
    105a:	83 fb 63             	cmp    $0x63,%ebx
    105d:	7f 10                	jg     106f <test+0x1f>
 
   printf("n %c\n", n);
    105f:	89 5c 24 04          	mov    %ebx,0x4(%esp)
    1063:	c7 04 24 b1 17 00 00 	movl   $0x17b1,(%esp)
    106a:	e8 a1 03 00 00       	call   1410 <printf>
   test(n+1);
    106f:	8d 43 01             	lea    0x1(%ebx),%eax
    1072:	89 04 24             	mov    %eax,(%esp)
    1075:	e8 d6 ff ff ff       	call   1050 <test>
//   printf("n %c\n", n);
   return n;
}
    107a:	83 c4 14             	add    $0x14,%esp
    107d:	89 d8                	mov    %ebx,%eax
    107f:	5b                   	pop    %ebx
    1080:	5d                   	pop    %ebp
    1081:	c3                   	ret    
    1082:	66 90                	xchg   %ax,%ax
    1084:	66 90                	xchg   %ax,%ax
    1086:	66 90                	xchg   %ax,%ax
    1088:	66 90                	xchg   %ax,%ax
    108a:	66 90                	xchg   %ax,%ax
    108c:	66 90                	xchg   %ax,%ax
    108e:	66 90                	xchg   %ax,%ax

00001090 <strcpy>:
    1090:	55                   	push   %ebp
    1091:	89 e5                	mov    %esp,%ebp
    1093:	8b 45 08             	mov    0x8(%ebp),%eax
    1096:	8b 4d 0c             	mov    0xc(%ebp),%ecx
    1099:	53                   	push   %ebx
    109a:	89 c2                	mov    %eax,%edx
    109c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    10a0:	83 c1 01             	add    $0x1,%ecx
    10a3:	0f b6 59 ff          	movzbl -0x1(%ecx),%ebx
    10a7:	83 c2 01             	add    $0x1,%edx
    10aa:	84 db                	test   %bl,%bl
    10ac:	88 5a ff             	mov    %bl,-0x1(%edx)
    10af:	75 ef                	jne    10a0 <strcpy+0x10>
    10b1:	5b                   	pop    %ebx
    10b2:	5d                   	pop    %ebp
    10b3:	c3                   	ret    
    10b4:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    10ba:	8d bf 00 00 00 00    	lea    0x0(%edi),%edi

000010c0 <strcmp>:
    10c0:	55                   	push   %ebp
    10c1:	89 e5                	mov    %esp,%ebp
    10c3:	8b 55 08             	mov    0x8(%ebp),%edx
    10c6:	53                   	push   %ebx
    10c7:	8b 4d 0c             	mov    0xc(%ebp),%ecx
    10ca:	0f b6 02             	movzbl (%edx),%eax
    10cd:	84 c0                	test   %al,%al
    10cf:	74 2d                	je     10fe <strcmp+0x3e>
    10d1:	0f b6 19             	movzbl (%ecx),%ebx
    10d4:	38 d8                	cmp    %bl,%al
    10d6:	74 0e                	je     10e6 <strcmp+0x26>
    10d8:	eb 2b                	jmp    1105 <strcmp+0x45>
    10da:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    10e0:	38 c8                	cmp    %cl,%al
    10e2:	75 15                	jne    10f9 <strcmp+0x39>
    10e4:	89 d9                	mov    %ebx,%ecx
    10e6:	83 c2 01             	add    $0x1,%edx
    10e9:	0f b6 02             	movzbl (%edx),%eax
    10ec:	8d 59 01             	lea    0x1(%ecx),%ebx
    10ef:	0f b6 49 01          	movzbl 0x1(%ecx),%ecx
    10f3:	84 c0                	test   %al,%al
    10f5:	75 e9                	jne    10e0 <strcmp+0x20>
    10f7:	31 c0                	xor    %eax,%eax
    10f9:	29 c8                	sub    %ecx,%eax
    10fb:	5b                   	pop    %ebx
    10fc:	5d                   	pop    %ebp
    10fd:	c3                   	ret    
    10fe:	0f b6 09             	movzbl (%ecx),%ecx
    1101:	31 c0                	xor    %eax,%eax
    1103:	eb f4                	jmp    10f9 <strcmp+0x39>
    1105:	0f b6 cb             	movzbl %bl,%ecx
    1108:	eb ef                	jmp    10f9 <strcmp+0x39>
    110a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

00001110 <strlen>:
    1110:	55                   	push   %ebp
    1111:	89 e5                	mov    %esp,%ebp
    1113:	8b 4d 08             	mov    0x8(%ebp),%ecx
    1116:	80 39 00             	cmpb   $0x0,(%ecx)
    1119:	74 12                	je     112d <strlen+0x1d>
    111b:	31 d2                	xor    %edx,%edx
    111d:	8d 76 00             	lea    0x0(%esi),%esi
    1120:	83 c2 01             	add    $0x1,%edx
    1123:	80 3c 11 00          	cmpb   $0x0,(%ecx,%edx,1)
    1127:	89 d0                	mov    %edx,%eax
    1129:	75 f5                	jne    1120 <strlen+0x10>
    112b:	5d                   	pop    %ebp
    112c:	c3                   	ret    
    112d:	31 c0                	xor    %eax,%eax
    112f:	5d                   	pop    %ebp
    1130:	c3                   	ret    
    1131:	eb 0d                	jmp    1140 <memset>
    1133:	90                   	nop
    1134:	90                   	nop
    1135:	90                   	nop
    1136:	90                   	nop
    1137:	90                   	nop
    1138:	90                   	nop
    1139:	90                   	nop
    113a:	90                   	nop
    113b:	90                   	nop
    113c:	90                   	nop
    113d:	90                   	nop
    113e:	90                   	nop
    113f:	90                   	nop

00001140 <memset>:
    1140:	55                   	push   %ebp
    1141:	89 e5                	mov    %esp,%ebp
    1143:	8b 55 08             	mov    0x8(%ebp),%edx
    1146:	57                   	push   %edi
    1147:	8b 4d 10             	mov    0x10(%ebp),%ecx
    114a:	8b 45 0c             	mov    0xc(%ebp),%eax
    114d:	89 d7                	mov    %edx,%edi
    114f:	fc                   	cld    
    1150:	f3 aa                	rep stos %al,%es:(%edi)
    1152:	89 d0                	mov    %edx,%eax
    1154:	5f                   	pop    %edi
    1155:	5d                   	pop    %ebp
    1156:	c3                   	ret    
    1157:	89 f6                	mov    %esi,%esi
    1159:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00001160 <strchr>:
    1160:	55                   	push   %ebp
    1161:	89 e5                	mov    %esp,%ebp
    1163:	8b 45 08             	mov    0x8(%ebp),%eax
    1166:	53                   	push   %ebx
    1167:	8b 55 0c             	mov    0xc(%ebp),%edx
    116a:	0f b6 18             	movzbl (%eax),%ebx
    116d:	84 db                	test   %bl,%bl
    116f:	74 1d                	je     118e <strchr+0x2e>
    1171:	38 d3                	cmp    %dl,%bl
    1173:	89 d1                	mov    %edx,%ecx
    1175:	75 0d                	jne    1184 <strchr+0x24>
    1177:	eb 17                	jmp    1190 <strchr+0x30>
    1179:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    1180:	38 ca                	cmp    %cl,%dl
    1182:	74 0c                	je     1190 <strchr+0x30>
    1184:	83 c0 01             	add    $0x1,%eax
    1187:	0f b6 10             	movzbl (%eax),%edx
    118a:	84 d2                	test   %dl,%dl
    118c:	75 f2                	jne    1180 <strchr+0x20>
    118e:	31 c0                	xor    %eax,%eax
    1190:	5b                   	pop    %ebx
    1191:	5d                   	pop    %ebp
    1192:	c3                   	ret    
    1193:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    1199:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

000011a0 <gets>:
    11a0:	55                   	push   %ebp
    11a1:	89 e5                	mov    %esp,%ebp
    11a3:	57                   	push   %edi
    11a4:	56                   	push   %esi
    11a5:	31 f6                	xor    %esi,%esi
    11a7:	53                   	push   %ebx
    11a8:	83 ec 2c             	sub    $0x2c,%esp
    11ab:	8d 7d e7             	lea    -0x19(%ebp),%edi
    11ae:	eb 31                	jmp    11e1 <gets+0x41>
    11b0:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    11b7:	00 
    11b8:	89 7c 24 04          	mov    %edi,0x4(%esp)
    11bc:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
    11c3:	e8 02 01 00 00       	call   12ca <read>
    11c8:	85 c0                	test   %eax,%eax
    11ca:	7e 1d                	jle    11e9 <gets+0x49>
    11cc:	0f b6 45 e7          	movzbl -0x19(%ebp),%eax
    11d0:	89 de                	mov    %ebx,%esi
    11d2:	8b 55 08             	mov    0x8(%ebp),%edx
    11d5:	3c 0d                	cmp    $0xd,%al
    11d7:	88 44 1a ff          	mov    %al,-0x1(%edx,%ebx,1)
    11db:	74 0c                	je     11e9 <gets+0x49>
    11dd:	3c 0a                	cmp    $0xa,%al
    11df:	74 08                	je     11e9 <gets+0x49>
    11e1:	8d 5e 01             	lea    0x1(%esi),%ebx
    11e4:	3b 5d 0c             	cmp    0xc(%ebp),%ebx
    11e7:	7c c7                	jl     11b0 <gets+0x10>
    11e9:	8b 45 08             	mov    0x8(%ebp),%eax
    11ec:	c6 04 30 00          	movb   $0x0,(%eax,%esi,1)
    11f0:	83 c4 2c             	add    $0x2c,%esp
    11f3:	5b                   	pop    %ebx
    11f4:	5e                   	pop    %esi
    11f5:	5f                   	pop    %edi
    11f6:	5d                   	pop    %ebp
    11f7:	c3                   	ret    
    11f8:	90                   	nop
    11f9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00001200 <stat>:
    1200:	55                   	push   %ebp
    1201:	89 e5                	mov    %esp,%ebp
    1203:	56                   	push   %esi
    1204:	53                   	push   %ebx
    1205:	83 ec 10             	sub    $0x10,%esp
    1208:	8b 45 08             	mov    0x8(%ebp),%eax
    120b:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
    1212:	00 
    1213:	89 04 24             	mov    %eax,(%esp)
    1216:	e8 d7 00 00 00       	call   12f2 <open>
    121b:	85 c0                	test   %eax,%eax
    121d:	89 c3                	mov    %eax,%ebx
    121f:	78 27                	js     1248 <stat+0x48>
    1221:	8b 45 0c             	mov    0xc(%ebp),%eax
    1224:	89 1c 24             	mov    %ebx,(%esp)
    1227:	89 44 24 04          	mov    %eax,0x4(%esp)
    122b:	e8 da 00 00 00       	call   130a <fstat>
    1230:	89 1c 24             	mov    %ebx,(%esp)
    1233:	89 c6                	mov    %eax,%esi
    1235:	e8 a0 00 00 00       	call   12da <close>
    123a:	89 f0                	mov    %esi,%eax
    123c:	83 c4 10             	add    $0x10,%esp
    123f:	5b                   	pop    %ebx
    1240:	5e                   	pop    %esi
    1241:	5d                   	pop    %ebp
    1242:	c3                   	ret    
    1243:	90                   	nop
    1244:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1248:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    124d:	eb ed                	jmp    123c <stat+0x3c>
    124f:	90                   	nop

00001250 <atoi>:
    1250:	55                   	push   %ebp
    1251:	89 e5                	mov    %esp,%ebp
    1253:	8b 4d 08             	mov    0x8(%ebp),%ecx
    1256:	53                   	push   %ebx
    1257:	0f be 11             	movsbl (%ecx),%edx
    125a:	8d 42 d0             	lea    -0x30(%edx),%eax
    125d:	3c 09                	cmp    $0x9,%al
    125f:	b8 00 00 00 00       	mov    $0x0,%eax
    1264:	77 17                	ja     127d <atoi+0x2d>
    1266:	66 90                	xchg   %ax,%ax
    1268:	83 c1 01             	add    $0x1,%ecx
    126b:	8d 04 80             	lea    (%eax,%eax,4),%eax
    126e:	8d 44 42 d0          	lea    -0x30(%edx,%eax,2),%eax
    1272:	0f be 11             	movsbl (%ecx),%edx
    1275:	8d 5a d0             	lea    -0x30(%edx),%ebx
    1278:	80 fb 09             	cmp    $0x9,%bl
    127b:	76 eb                	jbe    1268 <atoi+0x18>
    127d:	5b                   	pop    %ebx
    127e:	5d                   	pop    %ebp
    127f:	c3                   	ret    

00001280 <memmove>:
    1280:	55                   	push   %ebp
    1281:	31 d2                	xor    %edx,%edx
    1283:	89 e5                	mov    %esp,%ebp
    1285:	56                   	push   %esi
    1286:	8b 45 08             	mov    0x8(%ebp),%eax
    1289:	53                   	push   %ebx
    128a:	8b 5d 10             	mov    0x10(%ebp),%ebx
    128d:	8b 75 0c             	mov    0xc(%ebp),%esi
    1290:	85 db                	test   %ebx,%ebx
    1292:	7e 12                	jle    12a6 <memmove+0x26>
    1294:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1298:	0f b6 0c 16          	movzbl (%esi,%edx,1),%ecx
    129c:	88 0c 10             	mov    %cl,(%eax,%edx,1)
    129f:	83 c2 01             	add    $0x1,%edx
    12a2:	39 da                	cmp    %ebx,%edx
    12a4:	75 f2                	jne    1298 <memmove+0x18>
    12a6:	5b                   	pop    %ebx
    12a7:	5e                   	pop    %esi
    12a8:	5d                   	pop    %ebp
    12a9:	c3                   	ret    

000012aa <fork>:
    12aa:	b8 01 00 00 00       	mov    $0x1,%eax
    12af:	cd 40                	int    $0x40
    12b1:	c3                   	ret    

000012b2 <exit>:
    12b2:	b8 02 00 00 00       	mov    $0x2,%eax
    12b7:	cd 40                	int    $0x40
    12b9:	c3                   	ret    

000012ba <wait>:
    12ba:	b8 03 00 00 00       	mov    $0x3,%eax
    12bf:	cd 40                	int    $0x40
    12c1:	c3                   	ret    

000012c2 <pipe>:
    12c2:	b8 04 00 00 00       	mov    $0x4,%eax
    12c7:	cd 40                	int    $0x40
    12c9:	c3                   	ret    

000012ca <read>:
    12ca:	b8 05 00 00 00       	mov    $0x5,%eax
    12cf:	cd 40                	int    $0x40
    12d1:	c3                   	ret    

000012d2 <write>:
    12d2:	b8 10 00 00 00       	mov    $0x10,%eax
    12d7:	cd 40                	int    $0x40
    12d9:	c3                   	ret    

000012da <close>:
    12da:	b8 15 00 00 00       	mov    $0x15,%eax
    12df:	cd 40                	int    $0x40
    12e1:	c3                   	ret    

000012e2 <kill>:
    12e2:	b8 06 00 00 00       	mov    $0x6,%eax
    12e7:	cd 40                	int    $0x40
    12e9:	c3                   	ret    

000012ea <exec>:
    12ea:	b8 07 00 00 00       	mov    $0x7,%eax
    12ef:	cd 40                	int    $0x40
    12f1:	c3                   	ret    

000012f2 <open>:
    12f2:	b8 0f 00 00 00       	mov    $0xf,%eax
    12f7:	cd 40                	int    $0x40
    12f9:	c3                   	ret    

000012fa <mknod>:
    12fa:	b8 11 00 00 00       	mov    $0x11,%eax
    12ff:	cd 40                	int    $0x40
    1301:	c3                   	ret    

00001302 <unlink>:
    1302:	b8 12 00 00 00       	mov    $0x12,%eax
    1307:	cd 40                	int    $0x40
    1309:	c3                   	ret    

0000130a <fstat>:
    130a:	b8 08 00 00 00       	mov    $0x8,%eax
    130f:	cd 40                	int    $0x40
    1311:	c3                   	ret    

00001312 <link>:
    1312:	b8 13 00 00 00       	mov    $0x13,%eax
    1317:	cd 40                	int    $0x40
    1319:	c3                   	ret    

0000131a <mkdir>:
    131a:	b8 14 00 00 00       	mov    $0x14,%eax
    131f:	cd 40                	int    $0x40
    1321:	c3                   	ret    

00001322 <chdir>:
    1322:	b8 09 00 00 00       	mov    $0x9,%eax
    1327:	cd 40                	int    $0x40
    1329:	c3                   	ret    

0000132a <dup>:
    132a:	b8 0a 00 00 00       	mov    $0xa,%eax
    132f:	cd 40                	int    $0x40
    1331:	c3                   	ret    

00001332 <getpid>:
    1332:	b8 0b 00 00 00       	mov    $0xb,%eax
    1337:	cd 40                	int    $0x40
    1339:	c3                   	ret    

0000133a <sbrk>:
    133a:	b8 0c 00 00 00       	mov    $0xc,%eax
    133f:	cd 40                	int    $0x40
    1341:	c3                   	ret    

00001342 <sleep>:
    1342:	b8 0d 00 00 00       	mov    $0xd,%eax
    1347:	cd 40                	int    $0x40
    1349:	c3                   	ret    

0000134a <uptime>:
    134a:	b8 0e 00 00 00       	mov    $0xe,%eax
    134f:	cd 40                	int    $0x40
    1351:	c3                   	ret    

00001352 <shm_open>:
    1352:	b8 16 00 00 00       	mov    $0x16,%eax
    1357:	cd 40                	int    $0x40
    1359:	c3                   	ret    

0000135a <shm_close>:
    135a:	b8 17 00 00 00       	mov    $0x17,%eax
    135f:	cd 40                	int    $0x40
    1361:	c3                   	ret    
    1362:	66 90                	xchg   %ax,%ax
    1364:	66 90                	xchg   %ax,%ax
    1366:	66 90                	xchg   %ax,%ax
    1368:	66 90                	xchg   %ax,%ax
    136a:	66 90                	xchg   %ax,%ax
    136c:	66 90                	xchg   %ax,%ax
    136e:	66 90                	xchg   %ax,%ax

00001370 <printint>:
    1370:	55                   	push   %ebp
    1371:	89 e5                	mov    %esp,%ebp
    1373:	57                   	push   %edi
    1374:	56                   	push   %esi
    1375:	89 c6                	mov    %eax,%esi
    1377:	53                   	push   %ebx
    1378:	83 ec 4c             	sub    $0x4c,%esp
    137b:	8b 5d 08             	mov    0x8(%ebp),%ebx
    137e:	85 db                	test   %ebx,%ebx
    1380:	74 09                	je     138b <printint+0x1b>
    1382:	89 d0                	mov    %edx,%eax
    1384:	c1 e8 1f             	shr    $0x1f,%eax
    1387:	84 c0                	test   %al,%al
    1389:	75 75                	jne    1400 <printint+0x90>
    138b:	89 d0                	mov    %edx,%eax
    138d:	c7 45 c4 00 00 00 00 	movl   $0x0,-0x3c(%ebp)
    1394:	89 75 c0             	mov    %esi,-0x40(%ebp)
    1397:	31 ff                	xor    %edi,%edi
    1399:	89 ce                	mov    %ecx,%esi
    139b:	8d 5d d7             	lea    -0x29(%ebp),%ebx
    139e:	eb 02                	jmp    13a2 <printint+0x32>
    13a0:	89 cf                	mov    %ecx,%edi
    13a2:	31 d2                	xor    %edx,%edx
    13a4:	f7 f6                	div    %esi
    13a6:	8d 4f 01             	lea    0x1(%edi),%ecx
    13a9:	0f b6 92 c3 17 00 00 	movzbl 0x17c3(%edx),%edx
    13b0:	85 c0                	test   %eax,%eax
    13b2:	88 14 0b             	mov    %dl,(%ebx,%ecx,1)
    13b5:	75 e9                	jne    13a0 <printint+0x30>
    13b7:	8b 55 c4             	mov    -0x3c(%ebp),%edx
    13ba:	89 c8                	mov    %ecx,%eax
    13bc:	8b 75 c0             	mov    -0x40(%ebp),%esi
    13bf:	85 d2                	test   %edx,%edx
    13c1:	74 08                	je     13cb <printint+0x5b>
    13c3:	8d 4f 02             	lea    0x2(%edi),%ecx
    13c6:	c6 44 05 d8 2d       	movb   $0x2d,-0x28(%ebp,%eax,1)
    13cb:	8d 79 ff             	lea    -0x1(%ecx),%edi
    13ce:	66 90                	xchg   %ax,%ax
    13d0:	0f b6 44 3d d8       	movzbl -0x28(%ebp,%edi,1),%eax
    13d5:	83 ef 01             	sub    $0x1,%edi
    13d8:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    13df:	00 
    13e0:	89 5c 24 04          	mov    %ebx,0x4(%esp)
    13e4:	89 34 24             	mov    %esi,(%esp)
    13e7:	88 45 d7             	mov    %al,-0x29(%ebp)
    13ea:	e8 e3 fe ff ff       	call   12d2 <write>
    13ef:	83 ff ff             	cmp    $0xffffffff,%edi
    13f2:	75 dc                	jne    13d0 <printint+0x60>
    13f4:	83 c4 4c             	add    $0x4c,%esp
    13f7:	5b                   	pop    %ebx
    13f8:	5e                   	pop    %esi
    13f9:	5f                   	pop    %edi
    13fa:	5d                   	pop    %ebp
    13fb:	c3                   	ret    
    13fc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1400:	89 d0                	mov    %edx,%eax
    1402:	f7 d8                	neg    %eax
    1404:	c7 45 c4 01 00 00 00 	movl   $0x1,-0x3c(%ebp)
    140b:	eb 87                	jmp    1394 <printint+0x24>
    140d:	8d 76 00             	lea    0x0(%esi),%esi

00001410 <printf>:
    1410:	55                   	push   %ebp
    1411:	89 e5                	mov    %esp,%ebp
    1413:	57                   	push   %edi
    1414:	31 ff                	xor    %edi,%edi
    1416:	56                   	push   %esi
    1417:	53                   	push   %ebx
    1418:	83 ec 3c             	sub    $0x3c,%esp
    141b:	8b 5d 0c             	mov    0xc(%ebp),%ebx
    141e:	8d 45 10             	lea    0x10(%ebp),%eax
    1421:	8b 75 08             	mov    0x8(%ebp),%esi
    1424:	89 45 d4             	mov    %eax,-0x2c(%ebp)
    1427:	0f b6 13             	movzbl (%ebx),%edx
    142a:	83 c3 01             	add    $0x1,%ebx
    142d:	84 d2                	test   %dl,%dl
    142f:	75 39                	jne    146a <printf+0x5a>
    1431:	e9 c2 00 00 00       	jmp    14f8 <printf+0xe8>
    1436:	66 90                	xchg   %ax,%ax
    1438:	83 fa 25             	cmp    $0x25,%edx
    143b:	0f 84 bf 00 00 00    	je     1500 <printf+0xf0>
    1441:	8d 45 e2             	lea    -0x1e(%ebp),%eax
    1444:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    144b:	00 
    144c:	89 44 24 04          	mov    %eax,0x4(%esp)
    1450:	89 34 24             	mov    %esi,(%esp)
    1453:	88 55 e2             	mov    %dl,-0x1e(%ebp)
    1456:	e8 77 fe ff ff       	call   12d2 <write>
    145b:	83 c3 01             	add    $0x1,%ebx
    145e:	0f b6 53 ff          	movzbl -0x1(%ebx),%edx
    1462:	84 d2                	test   %dl,%dl
    1464:	0f 84 8e 00 00 00    	je     14f8 <printf+0xe8>
    146a:	85 ff                	test   %edi,%edi
    146c:	0f be c2             	movsbl %dl,%eax
    146f:	74 c7                	je     1438 <printf+0x28>
    1471:	83 ff 25             	cmp    $0x25,%edi
    1474:	75 e5                	jne    145b <printf+0x4b>
    1476:	83 fa 64             	cmp    $0x64,%edx
    1479:	0f 84 31 01 00 00    	je     15b0 <printf+0x1a0>
    147f:	25 f7 00 00 00       	and    $0xf7,%eax
    1484:	83 f8 70             	cmp    $0x70,%eax
    1487:	0f 84 83 00 00 00    	je     1510 <printf+0x100>
    148d:	83 fa 73             	cmp    $0x73,%edx
    1490:	0f 84 a2 00 00 00    	je     1538 <printf+0x128>
    1496:	83 fa 63             	cmp    $0x63,%edx
    1499:	0f 84 35 01 00 00    	je     15d4 <printf+0x1c4>
    149f:	83 fa 25             	cmp    $0x25,%edx
    14a2:	0f 84 e0 00 00 00    	je     1588 <printf+0x178>
    14a8:	8d 45 e6             	lea    -0x1a(%ebp),%eax
    14ab:	83 c3 01             	add    $0x1,%ebx
    14ae:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    14b5:	00 
    14b6:	31 ff                	xor    %edi,%edi
    14b8:	89 44 24 04          	mov    %eax,0x4(%esp)
    14bc:	89 34 24             	mov    %esi,(%esp)
    14bf:	89 55 d0             	mov    %edx,-0x30(%ebp)
    14c2:	c6 45 e6 25          	movb   $0x25,-0x1a(%ebp)
    14c6:	e8 07 fe ff ff       	call   12d2 <write>
    14cb:	8b 55 d0             	mov    -0x30(%ebp),%edx
    14ce:	8d 45 e7             	lea    -0x19(%ebp),%eax
    14d1:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    14d8:	00 
    14d9:	89 44 24 04          	mov    %eax,0x4(%esp)
    14dd:	89 34 24             	mov    %esi,(%esp)
    14e0:	88 55 e7             	mov    %dl,-0x19(%ebp)
    14e3:	e8 ea fd ff ff       	call   12d2 <write>
    14e8:	0f b6 53 ff          	movzbl -0x1(%ebx),%edx
    14ec:	84 d2                	test   %dl,%dl
    14ee:	0f 85 76 ff ff ff    	jne    146a <printf+0x5a>
    14f4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    14f8:	83 c4 3c             	add    $0x3c,%esp
    14fb:	5b                   	pop    %ebx
    14fc:	5e                   	pop    %esi
    14fd:	5f                   	pop    %edi
    14fe:	5d                   	pop    %ebp
    14ff:	c3                   	ret    
    1500:	bf 25 00 00 00       	mov    $0x25,%edi
    1505:	e9 51 ff ff ff       	jmp    145b <printf+0x4b>
    150a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    1510:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    1513:	b9 10 00 00 00       	mov    $0x10,%ecx
    1518:	31 ff                	xor    %edi,%edi
    151a:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
    1521:	8b 10                	mov    (%eax),%edx
    1523:	89 f0                	mov    %esi,%eax
    1525:	e8 46 fe ff ff       	call   1370 <printint>
    152a:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    152e:	e9 28 ff ff ff       	jmp    145b <printf+0x4b>
    1533:	90                   	nop
    1534:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1538:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    153b:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    153f:	8b 38                	mov    (%eax),%edi
    1541:	b8 bc 17 00 00       	mov    $0x17bc,%eax
    1546:	85 ff                	test   %edi,%edi
    1548:	0f 44 f8             	cmove  %eax,%edi
    154b:	0f b6 07             	movzbl (%edi),%eax
    154e:	84 c0                	test   %al,%al
    1550:	74 2a                	je     157c <printf+0x16c>
    1552:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    1558:	88 45 e3             	mov    %al,-0x1d(%ebp)
    155b:	8d 45 e3             	lea    -0x1d(%ebp),%eax
    155e:	83 c7 01             	add    $0x1,%edi
    1561:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1568:	00 
    1569:	89 44 24 04          	mov    %eax,0x4(%esp)
    156d:	89 34 24             	mov    %esi,(%esp)
    1570:	e8 5d fd ff ff       	call   12d2 <write>
    1575:	0f b6 07             	movzbl (%edi),%eax
    1578:	84 c0                	test   %al,%al
    157a:	75 dc                	jne    1558 <printf+0x148>
    157c:	31 ff                	xor    %edi,%edi
    157e:	e9 d8 fe ff ff       	jmp    145b <printf+0x4b>
    1583:	90                   	nop
    1584:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1588:	8d 45 e5             	lea    -0x1b(%ebp),%eax
    158b:	31 ff                	xor    %edi,%edi
    158d:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1594:	00 
    1595:	89 44 24 04          	mov    %eax,0x4(%esp)
    1599:	89 34 24             	mov    %esi,(%esp)
    159c:	c6 45 e5 25          	movb   $0x25,-0x1b(%ebp)
    15a0:	e8 2d fd ff ff       	call   12d2 <write>
    15a5:	e9 b1 fe ff ff       	jmp    145b <printf+0x4b>
    15aa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    15b0:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    15b3:	b9 0a 00 00 00       	mov    $0xa,%ecx
    15b8:	66 31 ff             	xor    %di,%di
    15bb:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    15c2:	8b 10                	mov    (%eax),%edx
    15c4:	89 f0                	mov    %esi,%eax
    15c6:	e8 a5 fd ff ff       	call   1370 <printint>
    15cb:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    15cf:	e9 87 fe ff ff       	jmp    145b <printf+0x4b>
    15d4:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    15d7:	31 ff                	xor    %edi,%edi
    15d9:	8b 00                	mov    (%eax),%eax
    15db:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    15e2:	00 
    15e3:	89 34 24             	mov    %esi,(%esp)
    15e6:	88 45 e4             	mov    %al,-0x1c(%ebp)
    15e9:	8d 45 e4             	lea    -0x1c(%ebp),%eax
    15ec:	89 44 24 04          	mov    %eax,0x4(%esp)
    15f0:	e8 dd fc ff ff       	call   12d2 <write>
    15f5:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    15f9:	e9 5d fe ff ff       	jmp    145b <printf+0x4b>
    15fe:	66 90                	xchg   %ax,%ax

00001600 <free>:
    1600:	55                   	push   %ebp
    1601:	a1 9c 1a 00 00       	mov    0x1a9c,%eax
    1606:	89 e5                	mov    %esp,%ebp
    1608:	57                   	push   %edi
    1609:	56                   	push   %esi
    160a:	53                   	push   %ebx
    160b:	8b 5d 08             	mov    0x8(%ebp),%ebx
    160e:	8b 08                	mov    (%eax),%ecx
    1610:	8d 53 f8             	lea    -0x8(%ebx),%edx
    1613:	39 d0                	cmp    %edx,%eax
    1615:	72 11                	jb     1628 <free+0x28>
    1617:	90                   	nop
    1618:	39 c8                	cmp    %ecx,%eax
    161a:	72 04                	jb     1620 <free+0x20>
    161c:	39 ca                	cmp    %ecx,%edx
    161e:	72 10                	jb     1630 <free+0x30>
    1620:	89 c8                	mov    %ecx,%eax
    1622:	39 d0                	cmp    %edx,%eax
    1624:	8b 08                	mov    (%eax),%ecx
    1626:	73 f0                	jae    1618 <free+0x18>
    1628:	39 ca                	cmp    %ecx,%edx
    162a:	72 04                	jb     1630 <free+0x30>
    162c:	39 c8                	cmp    %ecx,%eax
    162e:	72 f0                	jb     1620 <free+0x20>
    1630:	8b 73 fc             	mov    -0x4(%ebx),%esi
    1633:	8d 3c f2             	lea    (%edx,%esi,8),%edi
    1636:	39 cf                	cmp    %ecx,%edi
    1638:	74 1e                	je     1658 <free+0x58>
    163a:	89 4b f8             	mov    %ecx,-0x8(%ebx)
    163d:	8b 48 04             	mov    0x4(%eax),%ecx
    1640:	8d 34 c8             	lea    (%eax,%ecx,8),%esi
    1643:	39 f2                	cmp    %esi,%edx
    1645:	74 28                	je     166f <free+0x6f>
    1647:	89 10                	mov    %edx,(%eax)
    1649:	a3 9c 1a 00 00       	mov    %eax,0x1a9c
    164e:	5b                   	pop    %ebx
    164f:	5e                   	pop    %esi
    1650:	5f                   	pop    %edi
    1651:	5d                   	pop    %ebp
    1652:	c3                   	ret    
    1653:	90                   	nop
    1654:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1658:	03 71 04             	add    0x4(%ecx),%esi
    165b:	89 73 fc             	mov    %esi,-0x4(%ebx)
    165e:	8b 08                	mov    (%eax),%ecx
    1660:	8b 09                	mov    (%ecx),%ecx
    1662:	89 4b f8             	mov    %ecx,-0x8(%ebx)
    1665:	8b 48 04             	mov    0x4(%eax),%ecx
    1668:	8d 34 c8             	lea    (%eax,%ecx,8),%esi
    166b:	39 f2                	cmp    %esi,%edx
    166d:	75 d8                	jne    1647 <free+0x47>
    166f:	03 4b fc             	add    -0x4(%ebx),%ecx
    1672:	a3 9c 1a 00 00       	mov    %eax,0x1a9c
    1677:	89 48 04             	mov    %ecx,0x4(%eax)
    167a:	8b 53 f8             	mov    -0x8(%ebx),%edx
    167d:	89 10                	mov    %edx,(%eax)
    167f:	5b                   	pop    %ebx
    1680:	5e                   	pop    %esi
    1681:	5f                   	pop    %edi
    1682:	5d                   	pop    %ebp
    1683:	c3                   	ret    
    1684:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    168a:	8d bf 00 00 00 00    	lea    0x0(%edi),%edi

00001690 <malloc>:
    1690:	55                   	push   %ebp
    1691:	89 e5                	mov    %esp,%ebp
    1693:	57                   	push   %edi
    1694:	56                   	push   %esi
    1695:	53                   	push   %ebx
    1696:	83 ec 1c             	sub    $0x1c,%esp
    1699:	8b 45 08             	mov    0x8(%ebp),%eax
    169c:	8b 1d 9c 1a 00 00    	mov    0x1a9c,%ebx
    16a2:	8d 48 07             	lea    0x7(%eax),%ecx
    16a5:	c1 e9 03             	shr    $0x3,%ecx
    16a8:	85 db                	test   %ebx,%ebx
    16aa:	8d 71 01             	lea    0x1(%ecx),%esi
    16ad:	0f 84 9b 00 00 00    	je     174e <malloc+0xbe>
    16b3:	8b 13                	mov    (%ebx),%edx
    16b5:	8b 7a 04             	mov    0x4(%edx),%edi
    16b8:	39 fe                	cmp    %edi,%esi
    16ba:	76 64                	jbe    1720 <malloc+0x90>
    16bc:	8d 04 f5 00 00 00 00 	lea    0x0(,%esi,8),%eax
    16c3:	bb 00 80 00 00       	mov    $0x8000,%ebx
    16c8:	89 45 e4             	mov    %eax,-0x1c(%ebp)
    16cb:	eb 0e                	jmp    16db <malloc+0x4b>
    16cd:	8d 76 00             	lea    0x0(%esi),%esi
    16d0:	8b 02                	mov    (%edx),%eax
    16d2:	8b 78 04             	mov    0x4(%eax),%edi
    16d5:	39 fe                	cmp    %edi,%esi
    16d7:	76 4f                	jbe    1728 <malloc+0x98>
    16d9:	89 c2                	mov    %eax,%edx
    16db:	3b 15 9c 1a 00 00    	cmp    0x1a9c,%edx
    16e1:	75 ed                	jne    16d0 <malloc+0x40>
    16e3:	8b 45 e4             	mov    -0x1c(%ebp),%eax
    16e6:	81 fe 00 10 00 00    	cmp    $0x1000,%esi
    16ec:	bf 00 10 00 00       	mov    $0x1000,%edi
    16f1:	0f 43 fe             	cmovae %esi,%edi
    16f4:	0f 42 c3             	cmovb  %ebx,%eax
    16f7:	89 04 24             	mov    %eax,(%esp)
    16fa:	e8 3b fc ff ff       	call   133a <sbrk>
    16ff:	83 f8 ff             	cmp    $0xffffffff,%eax
    1702:	74 18                	je     171c <malloc+0x8c>
    1704:	89 78 04             	mov    %edi,0x4(%eax)
    1707:	83 c0 08             	add    $0x8,%eax
    170a:	89 04 24             	mov    %eax,(%esp)
    170d:	e8 ee fe ff ff       	call   1600 <free>
    1712:	8b 15 9c 1a 00 00    	mov    0x1a9c,%edx
    1718:	85 d2                	test   %edx,%edx
    171a:	75 b4                	jne    16d0 <malloc+0x40>
    171c:	31 c0                	xor    %eax,%eax
    171e:	eb 20                	jmp    1740 <malloc+0xb0>
    1720:	89 d0                	mov    %edx,%eax
    1722:	89 da                	mov    %ebx,%edx
    1724:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1728:	39 fe                	cmp    %edi,%esi
    172a:	74 1c                	je     1748 <malloc+0xb8>
    172c:	29 f7                	sub    %esi,%edi
    172e:	89 78 04             	mov    %edi,0x4(%eax)
    1731:	8d 04 f8             	lea    (%eax,%edi,8),%eax
    1734:	89 70 04             	mov    %esi,0x4(%eax)
    1737:	89 15 9c 1a 00 00    	mov    %edx,0x1a9c
    173d:	83 c0 08             	add    $0x8,%eax
    1740:	83 c4 1c             	add    $0x1c,%esp
    1743:	5b                   	pop    %ebx
    1744:	5e                   	pop    %esi
    1745:	5f                   	pop    %edi
    1746:	5d                   	pop    %ebp
    1747:	c3                   	ret    
    1748:	8b 08                	mov    (%eax),%ecx
    174a:	89 0a                	mov    %ecx,(%edx)
    174c:	eb e9                	jmp    1737 <malloc+0xa7>
    174e:	c7 05 9c 1a 00 00 a0 	movl   $0x1aa0,0x1a9c
    1755:	1a 00 00 
    1758:	ba a0 1a 00 00       	mov    $0x1aa0,%edx
    175d:	c7 05 a0 1a 00 00 a0 	movl   $0x1aa0,0x1aa0
    1764:	1a 00 00 
    1767:	c7 05 a4 1a 00 00 00 	movl   $0x0,0x1aa4
    176e:	00 00 00 
    1771:	e9 46 ff ff ff       	jmp    16bc <malloc+0x2c>
    1776:	66 90                	xchg   %ax,%ax
    1778:	66 90                	xchg   %ax,%ax
    177a:	66 90                	xchg   %ax,%ax
    177c:	66 90                	xchg   %ax,%ax
    177e:	66 90                	xchg   %ax,%ax

00001780 <uacquire>:
    1780:	55                   	push   %ebp
    1781:	b9 01 00 00 00       	mov    $0x1,%ecx
    1786:	89 e5                	mov    %esp,%ebp
    1788:	8b 55 08             	mov    0x8(%ebp),%edx
    178b:	90                   	nop
    178c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1790:	89 c8                	mov    %ecx,%eax
    1792:	f0 87 02             	lock xchg %eax,(%edx)
    1795:	85 c0                	test   %eax,%eax
    1797:	75 f7                	jne    1790 <uacquire+0x10>
    1799:	0f ae f0             	mfence 
    179c:	5d                   	pop    %ebp
    179d:	c3                   	ret    
    179e:	66 90                	xchg   %ax,%ax

000017a0 <urelease>:
    17a0:	55                   	push   %ebp
    17a1:	89 e5                	mov    %esp,%ebp
    17a3:	8b 45 08             	mov    0x8(%ebp),%eax
    17a6:	0f ae f0             	mfence 
    17a9:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
    17af:	5d                   	pop    %ebp
    17b0:	c3                   	ret    
