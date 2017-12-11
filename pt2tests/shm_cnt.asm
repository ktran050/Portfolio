
_shm_cnt:     file format elf32-i386


Disassembly of section .text:

00001000 <main>:
   struct uspinlock lock;
   int cnt;
};

int main(int argc, char *argv[])
{
    1000:	55                   	push   %ebp
    1001:	89 e5                	mov    %esp,%ebp
    1003:	57                   	push   %edi
//which we can now use but will be shared between the two processes
  
shm_open(1,(char **)&counter);
printf(1,"I reached past open\n"); 
//  printf(1,"%s returned successfully from shm_open with counter %x\n", pid? "Child": "Parent", counter); 
  for(i = 0; i < 10000; i++)
    1004:	31 ff                	xor    %edi,%edi
   struct uspinlock lock;
   int cnt;
};

int main(int argc, char *argv[])
{
    1006:	56                   	push   %esi
    1007:	53                   	push   %ebx
     uacquire(&(counter->lock));
     counter->cnt++;
     urelease(&(counter->lock));

//print something because we are curious and to give a chance to switch process
     if(i%1000 == 0)
    1008:	bb d3 4d 62 10       	mov    $0x10624dd3,%ebx
   struct uspinlock lock;
   int cnt;
};

int main(int argc, char *argv[])
{
    100d:	83 e4 f0             	and    $0xfffffff0,%esp
    1010:	83 ec 30             	sub    $0x30,%esp
int pid;
int i=0;
struct shm_cnt *counter;
  pid=fork();
    1013:	e8 72 03 00 00       	call   138a <fork>
  sleep(1);
    1018:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
int main(int argc, char *argv[])
{
int pid;
int i=0;
struct shm_cnt *counter;
  pid=fork();
    101f:	89 c6                	mov    %eax,%esi
  sleep(1);
    1021:	e8 fc 03 00 00       	call   1422 <sleep>

//shm_open: first process will create the page, the second will just attach to the same page
//we get the virtual address of the page returned into counter
//which we can now use but will be shared between the two processes
  
shm_open(1,(char **)&counter);
    1026:	8d 44 24 2c          	lea    0x2c(%esp),%eax
    102a:	89 44 24 04          	mov    %eax,0x4(%esp)
    102e:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1035:	e8 f8 03 00 00       	call   1432 <shm_open>
printf(1,"I reached past open\n"); 
    103a:	c7 44 24 04 a1 18 00 	movl   $0x18a1,0x4(%esp)
    1041:	00 
    1042:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1049:	e8 a2 04 00 00       	call   14f0 <printf>
    104e:	66 90                	xchg   %ax,%ax
//  printf(1,"%s returned successfully from shm_open with counter %x\n", pid? "Child": "Parent", counter); 
  for(i = 0; i < 10000; i++)
    {
     printf(1,"blah\n");
    1050:	c7 44 24 04 b6 18 00 	movl   $0x18b6,0x4(%esp)
    1057:	00 
    1058:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    105f:	e8 8c 04 00 00       	call   14f0 <printf>
     uacquire(&(counter->lock));
    1064:	8b 44 24 2c          	mov    0x2c(%esp),%eax
    1068:	89 04 24             	mov    %eax,(%esp)
    106b:	e8 f0 07 00 00       	call   1860 <uacquire>
     counter->cnt++;
    1070:	8b 44 24 2c          	mov    0x2c(%esp),%eax
    1074:	83 40 04 01          	addl   $0x1,0x4(%eax)
     urelease(&(counter->lock));
    1078:	89 04 24             	mov    %eax,(%esp)
    107b:	e8 00 08 00 00       	call   1880 <urelease>

//print something because we are curious and to give a chance to switch process
     if(i%1000 == 0)
    1080:	89 f8                	mov    %edi,%eax
    1082:	f7 eb                	imul   %ebx
    1084:	89 f8                	mov    %edi,%eax
    1086:	c1 f8 1f             	sar    $0x1f,%eax
    1089:	c1 fa 06             	sar    $0x6,%edx
    108c:	29 c2                	sub    %eax,%edx
    108e:	69 d2 e8 03 00 00    	imul   $0x3e8,%edx,%edx
    1094:	39 d7                	cmp    %edx,%edi
    1096:	75 3e                	jne    10d6 <main+0xd6>
       printf(1,"Counter in %s is %d at address %x\n",pid? "Parent" : "Child", counter->cnt, counter);
    1098:	8b 54 24 2c          	mov    0x2c(%esp),%edx
    109c:	b8 9b 18 00 00       	mov    $0x189b,%eax
    10a1:	85 f6                	test   %esi,%esi
    10a3:	8b 4a 04             	mov    0x4(%edx),%ecx
    10a6:	89 54 24 10          	mov    %edx,0x10(%esp)
    10aa:	c7 44 24 04 30 19 00 	movl   $0x1930,0x4(%esp)
    10b1:	00 
    10b2:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    10b9:	89 4c 24 1c          	mov    %ecx,0x1c(%esp)
    10bd:	b9 94 18 00 00       	mov    $0x1894,%ecx
    10c2:	0f 45 c1             	cmovne %ecx,%eax
    10c5:	8b 4c 24 1c          	mov    0x1c(%esp),%ecx
    10c9:	89 44 24 08          	mov    %eax,0x8(%esp)
    10cd:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
    10d1:	e8 1a 04 00 00       	call   14f0 <printf>
//which we can now use but will be shared between the two processes
  
shm_open(1,(char **)&counter);
printf(1,"I reached past open\n"); 
//  printf(1,"%s returned successfully from shm_open with counter %x\n", pid? "Child": "Parent", counter); 
  for(i = 0; i < 10000; i++)
    10d6:	83 c7 01             	add    $0x1,%edi
    10d9:	81 ff 10 27 00 00    	cmp    $0x2710,%edi
    10df:	0f 85 6b ff ff ff    	jne    1050 <main+0x50>

//print something because we are curious and to give a chance to switch process
     if(i%1000 == 0)
       printf(1,"Counter in %s is %d at address %x\n",pid? "Parent" : "Child", counter->cnt, counter);
}
printf(1, "I got past the for loop\n"); 
    10e5:	c7 44 24 04 bc 18 00 	movl   $0x18bc,0x4(%esp)
    10ec:	00 
    10ed:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    10f4:	e8 f7 03 00 00       	call   14f0 <printf>
  if(pid)
     {
       printf(1,"Counter in parent is %d\n",counter->cnt);
    10f9:	8b 44 24 2c          	mov    0x2c(%esp),%eax
//print something because we are curious and to give a chance to switch process
     if(i%1000 == 0)
       printf(1,"Counter in %s is %d at address %x\n",pid? "Parent" : "Child", counter->cnt, counter);
}
printf(1, "I got past the for loop\n"); 
  if(pid)
    10fd:	85 f6                	test   %esi,%esi
     {
       printf(1,"Counter in parent is %d\n",counter->cnt);
    10ff:	8b 40 04             	mov    0x4(%eax),%eax
    1102:	89 44 24 08          	mov    %eax,0x8(%esp)
//print something because we are curious and to give a chance to switch process
     if(i%1000 == 0)
       printf(1,"Counter in %s is %d at address %x\n",pid? "Parent" : "Child", counter->cnt, counter);
}
printf(1, "I got past the for loop\n"); 
  if(pid)
    1106:	74 52                	je     115a <main+0x15a>
     {
       printf(1,"Counter in parent is %d\n",counter->cnt);
    1108:	c7 44 24 04 d5 18 00 	movl   $0x18d5,0x4(%esp)
    110f:	00 
    1110:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1117:	e8 d4 03 00 00       	call   14f0 <printf>
    wait();
    111c:	e8 79 02 00 00       	call   139a <wait>
    } else
    printf(1,"Counter in child is %d\n\n",counter->cnt);

//shm_close: first process will just detach, next one will free up the shm_table entry (but for now not the page)
   printf(1,"I got to close\n");
    1121:	c7 44 24 04 07 19 00 	movl   $0x1907,0x4(%esp)
    1128:	00 
    1129:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1130:	e8 bb 03 00 00       	call   14f0 <printf>
   shm_close(1);
    1135:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    113c:	e8 f9 02 00 00       	call   143a <shm_close>
   printf(1,"I reached past close\n");
    1141:	c7 44 24 04 17 19 00 	movl   $0x1917,0x4(%esp)
    1148:	00 
    1149:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1150:	e8 9b 03 00 00       	call   14f0 <printf>
   exit();
    1155:	e8 38 02 00 00       	call   1392 <exit>
  if(pid)
     {
       printf(1,"Counter in parent is %d\n",counter->cnt);
    wait();
    } else
    printf(1,"Counter in child is %d\n\n",counter->cnt);
    115a:	c7 44 24 04 ee 18 00 	movl   $0x18ee,0x4(%esp)
    1161:	00 
    1162:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    1169:	e8 82 03 00 00       	call   14f0 <printf>
    116e:	eb b1                	jmp    1121 <main+0x121>

00001170 <strcpy>:
#include "user.h"
#include "x86.h"

char*
strcpy(char *s, char *t)
{
    1170:	55                   	push   %ebp
    1171:	89 e5                	mov    %esp,%ebp
    1173:	8b 45 08             	mov    0x8(%ebp),%eax
    1176:	8b 4d 0c             	mov    0xc(%ebp),%ecx
    1179:	53                   	push   %ebx
  char *os;

  os = s;
  while((*s++ = *t++) != 0)
    117a:	89 c2                	mov    %eax,%edx
    117c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1180:	83 c1 01             	add    $0x1,%ecx
    1183:	0f b6 59 ff          	movzbl -0x1(%ecx),%ebx
    1187:	83 c2 01             	add    $0x1,%edx
    118a:	84 db                	test   %bl,%bl
    118c:	88 5a ff             	mov    %bl,-0x1(%edx)
    118f:	75 ef                	jne    1180 <strcpy+0x10>
    ;
  return os;
}
    1191:	5b                   	pop    %ebx
    1192:	5d                   	pop    %ebp
    1193:	c3                   	ret    
    1194:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    119a:	8d bf 00 00 00 00    	lea    0x0(%edi),%edi

000011a0 <strcmp>:

int
strcmp(const char *p, const char *q)
{
    11a0:	55                   	push   %ebp
    11a1:	89 e5                	mov    %esp,%ebp
    11a3:	8b 55 08             	mov    0x8(%ebp),%edx
    11a6:	53                   	push   %ebx
    11a7:	8b 4d 0c             	mov    0xc(%ebp),%ecx
  while(*p && *p == *q)
    11aa:	0f b6 02             	movzbl (%edx),%eax
    11ad:	84 c0                	test   %al,%al
    11af:	74 2d                	je     11de <strcmp+0x3e>
    11b1:	0f b6 19             	movzbl (%ecx),%ebx
    11b4:	38 d8                	cmp    %bl,%al
    11b6:	74 0e                	je     11c6 <strcmp+0x26>
    11b8:	eb 2b                	jmp    11e5 <strcmp+0x45>
    11ba:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    11c0:	38 c8                	cmp    %cl,%al
    11c2:	75 15                	jne    11d9 <strcmp+0x39>
    p++, q++;
    11c4:	89 d9                	mov    %ebx,%ecx
    11c6:	83 c2 01             	add    $0x1,%edx
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    11c9:	0f b6 02             	movzbl (%edx),%eax
    p++, q++;
    11cc:	8d 59 01             	lea    0x1(%ecx),%ebx
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    11cf:	0f b6 49 01          	movzbl 0x1(%ecx),%ecx
    11d3:	84 c0                	test   %al,%al
    11d5:	75 e9                	jne    11c0 <strcmp+0x20>
    11d7:	31 c0                	xor    %eax,%eax
    p++, q++;
  return (uchar)*p - (uchar)*q;
    11d9:	29 c8                	sub    %ecx,%eax
}
    11db:	5b                   	pop    %ebx
    11dc:	5d                   	pop    %ebp
    11dd:	c3                   	ret    
    11de:	0f b6 09             	movzbl (%ecx),%ecx
}

int
strcmp(const char *p, const char *q)
{
  while(*p && *p == *q)
    11e1:	31 c0                	xor    %eax,%eax
    11e3:	eb f4                	jmp    11d9 <strcmp+0x39>
    11e5:	0f b6 cb             	movzbl %bl,%ecx
    11e8:	eb ef                	jmp    11d9 <strcmp+0x39>
    11ea:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

000011f0 <strlen>:
  return (uchar)*p - (uchar)*q;
}

uint
strlen(char *s)
{
    11f0:	55                   	push   %ebp
    11f1:	89 e5                	mov    %esp,%ebp
    11f3:	8b 4d 08             	mov    0x8(%ebp),%ecx
  int n;

  for(n = 0; s[n]; n++)
    11f6:	80 39 00             	cmpb   $0x0,(%ecx)
    11f9:	74 12                	je     120d <strlen+0x1d>
    11fb:	31 d2                	xor    %edx,%edx
    11fd:	8d 76 00             	lea    0x0(%esi),%esi
    1200:	83 c2 01             	add    $0x1,%edx
    1203:	80 3c 11 00          	cmpb   $0x0,(%ecx,%edx,1)
    1207:	89 d0                	mov    %edx,%eax
    1209:	75 f5                	jne    1200 <strlen+0x10>
    ;
  return n;
}
    120b:	5d                   	pop    %ebp
    120c:	c3                   	ret    
uint
strlen(char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    120d:	31 c0                	xor    %eax,%eax
    ;
  return n;
}
    120f:	5d                   	pop    %ebp
    1210:	c3                   	ret    
    1211:	eb 0d                	jmp    1220 <memset>
    1213:	90                   	nop
    1214:	90                   	nop
    1215:	90                   	nop
    1216:	90                   	nop
    1217:	90                   	nop
    1218:	90                   	nop
    1219:	90                   	nop
    121a:	90                   	nop
    121b:	90                   	nop
    121c:	90                   	nop
    121d:	90                   	nop
    121e:	90                   	nop
    121f:	90                   	nop

00001220 <memset>:

void*
memset(void *dst, int c, uint n)
{
    1220:	55                   	push   %ebp
    1221:	89 e5                	mov    %esp,%ebp
    1223:	8b 55 08             	mov    0x8(%ebp),%edx
    1226:	57                   	push   %edi
}

static inline void
stosb(void *addr, int data, int cnt)
{
  asm volatile("cld; rep stosb" :
    1227:	8b 4d 10             	mov    0x10(%ebp),%ecx
    122a:	8b 45 0c             	mov    0xc(%ebp),%eax
    122d:	89 d7                	mov    %edx,%edi
    122f:	fc                   	cld    
    1230:	f3 aa                	rep stos %al,%es:(%edi)
  stosb(dst, c, n);
  return dst;
}
    1232:	89 d0                	mov    %edx,%eax
    1234:	5f                   	pop    %edi
    1235:	5d                   	pop    %ebp
    1236:	c3                   	ret    
    1237:	89 f6                	mov    %esi,%esi
    1239:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00001240 <strchr>:

char*
strchr(const char *s, char c)
{
    1240:	55                   	push   %ebp
    1241:	89 e5                	mov    %esp,%ebp
    1243:	8b 45 08             	mov    0x8(%ebp),%eax
    1246:	53                   	push   %ebx
    1247:	8b 55 0c             	mov    0xc(%ebp),%edx
  for(; *s; s++)
    124a:	0f b6 18             	movzbl (%eax),%ebx
    124d:	84 db                	test   %bl,%bl
    124f:	74 1d                	je     126e <strchr+0x2e>
    if(*s == c)
    1251:	38 d3                	cmp    %dl,%bl
    1253:	89 d1                	mov    %edx,%ecx
    1255:	75 0d                	jne    1264 <strchr+0x24>
    1257:	eb 17                	jmp    1270 <strchr+0x30>
    1259:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
    1260:	38 ca                	cmp    %cl,%dl
    1262:	74 0c                	je     1270 <strchr+0x30>
}

char*
strchr(const char *s, char c)
{
  for(; *s; s++)
    1264:	83 c0 01             	add    $0x1,%eax
    1267:	0f b6 10             	movzbl (%eax),%edx
    126a:	84 d2                	test   %dl,%dl
    126c:	75 f2                	jne    1260 <strchr+0x20>
    if(*s == c)
      return (char*)s;
  return 0;
    126e:	31 c0                	xor    %eax,%eax
}
    1270:	5b                   	pop    %ebx
    1271:	5d                   	pop    %ebp
    1272:	c3                   	ret    
    1273:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    1279:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

00001280 <gets>:

char*
gets(char *buf, int max)
{
    1280:	55                   	push   %ebp
    1281:	89 e5                	mov    %esp,%ebp
    1283:	57                   	push   %edi
    1284:	56                   	push   %esi
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    1285:	31 f6                	xor    %esi,%esi
  return 0;
}

char*
gets(char *buf, int max)
{
    1287:	53                   	push   %ebx
    1288:	83 ec 2c             	sub    $0x2c,%esp
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    cc = read(0, &c, 1);
    128b:	8d 7d e7             	lea    -0x19(%ebp),%edi
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    128e:	eb 31                	jmp    12c1 <gets+0x41>
    cc = read(0, &c, 1);
    1290:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1297:	00 
    1298:	89 7c 24 04          	mov    %edi,0x4(%esp)
    129c:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
    12a3:	e8 02 01 00 00       	call   13aa <read>
    if(cc < 1)
    12a8:	85 c0                	test   %eax,%eax
    12aa:	7e 1d                	jle    12c9 <gets+0x49>
      break;
    buf[i++] = c;
    12ac:	0f b6 45 e7          	movzbl -0x19(%ebp),%eax
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    12b0:	89 de                	mov    %ebx,%esi
    cc = read(0, &c, 1);
    if(cc < 1)
      break;
    buf[i++] = c;
    12b2:	8b 55 08             	mov    0x8(%ebp),%edx
    if(c == '\n' || c == '\r')
    12b5:	3c 0d                	cmp    $0xd,%al

  for(i=0; i+1 < max; ){
    cc = read(0, &c, 1);
    if(cc < 1)
      break;
    buf[i++] = c;
    12b7:	88 44 1a ff          	mov    %al,-0x1(%edx,%ebx,1)
    if(c == '\n' || c == '\r')
    12bb:	74 0c                	je     12c9 <gets+0x49>
    12bd:	3c 0a                	cmp    $0xa,%al
    12bf:	74 08                	je     12c9 <gets+0x49>
gets(char *buf, int max)
{
  int i, cc;
  char c;

  for(i=0; i+1 < max; ){
    12c1:	8d 5e 01             	lea    0x1(%esi),%ebx
    12c4:	3b 5d 0c             	cmp    0xc(%ebp),%ebx
    12c7:	7c c7                	jl     1290 <gets+0x10>
      break;
    buf[i++] = c;
    if(c == '\n' || c == '\r')
      break;
  }
  buf[i] = '\0';
    12c9:	8b 45 08             	mov    0x8(%ebp),%eax
    12cc:	c6 04 30 00          	movb   $0x0,(%eax,%esi,1)
  return buf;
}
    12d0:	83 c4 2c             	add    $0x2c,%esp
    12d3:	5b                   	pop    %ebx
    12d4:	5e                   	pop    %esi
    12d5:	5f                   	pop    %edi
    12d6:	5d                   	pop    %ebp
    12d7:	c3                   	ret    
    12d8:	90                   	nop
    12d9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

000012e0 <stat>:

int
stat(char *n, struct stat *st)
{
    12e0:	55                   	push   %ebp
    12e1:	89 e5                	mov    %esp,%ebp
    12e3:	56                   	push   %esi
    12e4:	53                   	push   %ebx
    12e5:	83 ec 10             	sub    $0x10,%esp
  int fd;
  int r;

  fd = open(n, O_RDONLY);
    12e8:	8b 45 08             	mov    0x8(%ebp),%eax
    12eb:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
    12f2:	00 
    12f3:	89 04 24             	mov    %eax,(%esp)
    12f6:	e8 d7 00 00 00       	call   13d2 <open>
  if(fd < 0)
    12fb:	85 c0                	test   %eax,%eax
stat(char *n, struct stat *st)
{
  int fd;
  int r;

  fd = open(n, O_RDONLY);
    12fd:	89 c3                	mov    %eax,%ebx
  if(fd < 0)
    12ff:	78 27                	js     1328 <stat+0x48>
    return -1;
  r = fstat(fd, st);
    1301:	8b 45 0c             	mov    0xc(%ebp),%eax
    1304:	89 1c 24             	mov    %ebx,(%esp)
    1307:	89 44 24 04          	mov    %eax,0x4(%esp)
    130b:	e8 da 00 00 00       	call   13ea <fstat>
  close(fd);
    1310:	89 1c 24             	mov    %ebx,(%esp)
  int r;

  fd = open(n, O_RDONLY);
  if(fd < 0)
    return -1;
  r = fstat(fd, st);
    1313:	89 c6                	mov    %eax,%esi
  close(fd);
    1315:	e8 a0 00 00 00       	call   13ba <close>
  return r;
    131a:	89 f0                	mov    %esi,%eax
}
    131c:	83 c4 10             	add    $0x10,%esp
    131f:	5b                   	pop    %ebx
    1320:	5e                   	pop    %esi
    1321:	5d                   	pop    %ebp
    1322:	c3                   	ret    
    1323:	90                   	nop
    1324:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  int fd;
  int r;

  fd = open(n, O_RDONLY);
  if(fd < 0)
    return -1;
    1328:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    132d:	eb ed                	jmp    131c <stat+0x3c>
    132f:	90                   	nop

00001330 <atoi>:
  return r;
}

int
atoi(const char *s)
{
    1330:	55                   	push   %ebp
    1331:	89 e5                	mov    %esp,%ebp
    1333:	8b 4d 08             	mov    0x8(%ebp),%ecx
    1336:	53                   	push   %ebx
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    1337:	0f be 11             	movsbl (%ecx),%edx
    133a:	8d 42 d0             	lea    -0x30(%edx),%eax
    133d:	3c 09                	cmp    $0x9,%al
int
atoi(const char *s)
{
  int n;

  n = 0;
    133f:	b8 00 00 00 00       	mov    $0x0,%eax
  while('0' <= *s && *s <= '9')
    1344:	77 17                	ja     135d <atoi+0x2d>
    1346:	66 90                	xchg   %ax,%ax
    n = n*10 + *s++ - '0';
    1348:	83 c1 01             	add    $0x1,%ecx
    134b:	8d 04 80             	lea    (%eax,%eax,4),%eax
    134e:	8d 44 42 d0          	lea    -0x30(%edx,%eax,2),%eax
atoi(const char *s)
{
  int n;

  n = 0;
  while('0' <= *s && *s <= '9')
    1352:	0f be 11             	movsbl (%ecx),%edx
    1355:	8d 5a d0             	lea    -0x30(%edx),%ebx
    1358:	80 fb 09             	cmp    $0x9,%bl
    135b:	76 eb                	jbe    1348 <atoi+0x18>
    n = n*10 + *s++ - '0';
  return n;
}
    135d:	5b                   	pop    %ebx
    135e:	5d                   	pop    %ebp
    135f:	c3                   	ret    

00001360 <memmove>:

void*
memmove(void *vdst, void *vsrc, int n)
{
    1360:	55                   	push   %ebp
  char *dst, *src;

  dst = vdst;
  src = vsrc;
  while(n-- > 0)
    1361:	31 d2                	xor    %edx,%edx
  return n;
}

void*
memmove(void *vdst, void *vsrc, int n)
{
    1363:	89 e5                	mov    %esp,%ebp
    1365:	56                   	push   %esi
    1366:	8b 45 08             	mov    0x8(%ebp),%eax
    1369:	53                   	push   %ebx
    136a:	8b 5d 10             	mov    0x10(%ebp),%ebx
    136d:	8b 75 0c             	mov    0xc(%ebp),%esi
  char *dst, *src;

  dst = vdst;
  src = vsrc;
  while(n-- > 0)
    1370:	85 db                	test   %ebx,%ebx
    1372:	7e 12                	jle    1386 <memmove+0x26>
    1374:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    *dst++ = *src++;
    1378:	0f b6 0c 16          	movzbl (%esi,%edx,1),%ecx
    137c:	88 0c 10             	mov    %cl,(%eax,%edx,1)
    137f:	83 c2 01             	add    $0x1,%edx
{
  char *dst, *src;

  dst = vdst;
  src = vsrc;
  while(n-- > 0)
    1382:	39 da                	cmp    %ebx,%edx
    1384:	75 f2                	jne    1378 <memmove+0x18>
    *dst++ = *src++;
  return vdst;
}
    1386:	5b                   	pop    %ebx
    1387:	5e                   	pop    %esi
    1388:	5d                   	pop    %ebp
    1389:	c3                   	ret    

0000138a <fork>:
  name: \
    movl $SYS_ ## name, %eax; \
    int $T_SYSCALL; \
    ret

SYSCALL(fork)
    138a:	b8 01 00 00 00       	mov    $0x1,%eax
    138f:	cd 40                	int    $0x40
    1391:	c3                   	ret    

00001392 <exit>:
SYSCALL(exit)
    1392:	b8 02 00 00 00       	mov    $0x2,%eax
    1397:	cd 40                	int    $0x40
    1399:	c3                   	ret    

0000139a <wait>:
SYSCALL(wait)
    139a:	b8 03 00 00 00       	mov    $0x3,%eax
    139f:	cd 40                	int    $0x40
    13a1:	c3                   	ret    

000013a2 <pipe>:
SYSCALL(pipe)
    13a2:	b8 04 00 00 00       	mov    $0x4,%eax
    13a7:	cd 40                	int    $0x40
    13a9:	c3                   	ret    

000013aa <read>:
SYSCALL(read)
    13aa:	b8 05 00 00 00       	mov    $0x5,%eax
    13af:	cd 40                	int    $0x40
    13b1:	c3                   	ret    

000013b2 <write>:
SYSCALL(write)
    13b2:	b8 10 00 00 00       	mov    $0x10,%eax
    13b7:	cd 40                	int    $0x40
    13b9:	c3                   	ret    

000013ba <close>:
SYSCALL(close)
    13ba:	b8 15 00 00 00       	mov    $0x15,%eax
    13bf:	cd 40                	int    $0x40
    13c1:	c3                   	ret    

000013c2 <kill>:
SYSCALL(kill)
    13c2:	b8 06 00 00 00       	mov    $0x6,%eax
    13c7:	cd 40                	int    $0x40
    13c9:	c3                   	ret    

000013ca <exec>:
SYSCALL(exec)
    13ca:	b8 07 00 00 00       	mov    $0x7,%eax
    13cf:	cd 40                	int    $0x40
    13d1:	c3                   	ret    

000013d2 <open>:
SYSCALL(open)
    13d2:	b8 0f 00 00 00       	mov    $0xf,%eax
    13d7:	cd 40                	int    $0x40
    13d9:	c3                   	ret    

000013da <mknod>:
SYSCALL(mknod)
    13da:	b8 11 00 00 00       	mov    $0x11,%eax
    13df:	cd 40                	int    $0x40
    13e1:	c3                   	ret    

000013e2 <unlink>:
SYSCALL(unlink)
    13e2:	b8 12 00 00 00       	mov    $0x12,%eax
    13e7:	cd 40                	int    $0x40
    13e9:	c3                   	ret    

000013ea <fstat>:
SYSCALL(fstat)
    13ea:	b8 08 00 00 00       	mov    $0x8,%eax
    13ef:	cd 40                	int    $0x40
    13f1:	c3                   	ret    

000013f2 <link>:
SYSCALL(link)
    13f2:	b8 13 00 00 00       	mov    $0x13,%eax
    13f7:	cd 40                	int    $0x40
    13f9:	c3                   	ret    

000013fa <mkdir>:
SYSCALL(mkdir)
    13fa:	b8 14 00 00 00       	mov    $0x14,%eax
    13ff:	cd 40                	int    $0x40
    1401:	c3                   	ret    

00001402 <chdir>:
SYSCALL(chdir)
    1402:	b8 09 00 00 00       	mov    $0x9,%eax
    1407:	cd 40                	int    $0x40
    1409:	c3                   	ret    

0000140a <dup>:
SYSCALL(dup)
    140a:	b8 0a 00 00 00       	mov    $0xa,%eax
    140f:	cd 40                	int    $0x40
    1411:	c3                   	ret    

00001412 <getpid>:
SYSCALL(getpid)
    1412:	b8 0b 00 00 00       	mov    $0xb,%eax
    1417:	cd 40                	int    $0x40
    1419:	c3                   	ret    

0000141a <sbrk>:
SYSCALL(sbrk)
    141a:	b8 0c 00 00 00       	mov    $0xc,%eax
    141f:	cd 40                	int    $0x40
    1421:	c3                   	ret    

00001422 <sleep>:
SYSCALL(sleep)
    1422:	b8 0d 00 00 00       	mov    $0xd,%eax
    1427:	cd 40                	int    $0x40
    1429:	c3                   	ret    

0000142a <uptime>:
SYSCALL(uptime)
    142a:	b8 0e 00 00 00       	mov    $0xe,%eax
    142f:	cd 40                	int    $0x40
    1431:	c3                   	ret    

00001432 <shm_open>:
SYSCALL(shm_open)
    1432:	b8 16 00 00 00       	mov    $0x16,%eax
    1437:	cd 40                	int    $0x40
    1439:	c3                   	ret    

0000143a <shm_close>:
SYSCALL(shm_close)	
    143a:	b8 17 00 00 00       	mov    $0x17,%eax
    143f:	cd 40                	int    $0x40
    1441:	c3                   	ret    
    1442:	66 90                	xchg   %ax,%ax
    1444:	66 90                	xchg   %ax,%ax
    1446:	66 90                	xchg   %ax,%ax
    1448:	66 90                	xchg   %ax,%ax
    144a:	66 90                	xchg   %ax,%ax
    144c:	66 90                	xchg   %ax,%ax
    144e:	66 90                	xchg   %ax,%ax

00001450 <printint>:
  write(fd, &c, 1);
}

static void
printint(int fd, int xx, int base, int sgn)
{
    1450:	55                   	push   %ebp
    1451:	89 e5                	mov    %esp,%ebp
    1453:	57                   	push   %edi
    1454:	56                   	push   %esi
    1455:	89 c6                	mov    %eax,%esi
    1457:	53                   	push   %ebx
    1458:	83 ec 4c             	sub    $0x4c,%esp
  char buf[16];
  int i, neg;
  uint x;

  neg = 0;
  if(sgn && xx < 0){
    145b:	8b 5d 08             	mov    0x8(%ebp),%ebx
    145e:	85 db                	test   %ebx,%ebx
    1460:	74 09                	je     146b <printint+0x1b>
    1462:	89 d0                	mov    %edx,%eax
    1464:	c1 e8 1f             	shr    $0x1f,%eax
    1467:	84 c0                	test   %al,%al
    1469:	75 75                	jne    14e0 <printint+0x90>
    neg = 1;
    x = -xx;
  } else {
    x = xx;
    146b:	89 d0                	mov    %edx,%eax
  static char digits[] = "0123456789ABCDEF";
  char buf[16];
  int i, neg;
  uint x;

  neg = 0;
    146d:	c7 45 c4 00 00 00 00 	movl   $0x0,-0x3c(%ebp)
    1474:	89 75 c0             	mov    %esi,-0x40(%ebp)
    x = -xx;
  } else {
    x = xx;
  }

  i = 0;
    1477:	31 ff                	xor    %edi,%edi
    1479:	89 ce                	mov    %ecx,%esi
    147b:	8d 5d d7             	lea    -0x29(%ebp),%ebx
    147e:	eb 02                	jmp    1482 <printint+0x32>
  do{
    buf[i++] = digits[x % base];
    1480:	89 cf                	mov    %ecx,%edi
    1482:	31 d2                	xor    %edx,%edx
    1484:	f7 f6                	div    %esi
    1486:	8d 4f 01             	lea    0x1(%edi),%ecx
    1489:	0f b6 92 5b 19 00 00 	movzbl 0x195b(%edx),%edx
  }while((x /= base) != 0);
    1490:	85 c0                	test   %eax,%eax
    x = xx;
  }

  i = 0;
  do{
    buf[i++] = digits[x % base];
    1492:	88 14 0b             	mov    %dl,(%ebx,%ecx,1)
  }while((x /= base) != 0);
    1495:	75 e9                	jne    1480 <printint+0x30>
  if(neg)
    1497:	8b 55 c4             	mov    -0x3c(%ebp),%edx
    x = xx;
  }

  i = 0;
  do{
    buf[i++] = digits[x % base];
    149a:	89 c8                	mov    %ecx,%eax
    149c:	8b 75 c0             	mov    -0x40(%ebp),%esi
  }while((x /= base) != 0);
  if(neg)
    149f:	85 d2                	test   %edx,%edx
    14a1:	74 08                	je     14ab <printint+0x5b>
    buf[i++] = '-';
    14a3:	8d 4f 02             	lea    0x2(%edi),%ecx
    14a6:	c6 44 05 d8 2d       	movb   $0x2d,-0x28(%ebp,%eax,1)

  while(--i >= 0)
    14ab:	8d 79 ff             	lea    -0x1(%ecx),%edi
    14ae:	66 90                	xchg   %ax,%ax
    14b0:	0f b6 44 3d d8       	movzbl -0x28(%ebp,%edi,1),%eax
    14b5:	83 ef 01             	sub    $0x1,%edi
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    14b8:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    14bf:	00 
    14c0:	89 5c 24 04          	mov    %ebx,0x4(%esp)
    14c4:	89 34 24             	mov    %esi,(%esp)
    14c7:	88 45 d7             	mov    %al,-0x29(%ebp)
    14ca:	e8 e3 fe ff ff       	call   13b2 <write>
    buf[i++] = digits[x % base];
  }while((x /= base) != 0);
  if(neg)
    buf[i++] = '-';

  while(--i >= 0)
    14cf:	83 ff ff             	cmp    $0xffffffff,%edi
    14d2:	75 dc                	jne    14b0 <printint+0x60>
    putc(fd, buf[i]);
}
    14d4:	83 c4 4c             	add    $0x4c,%esp
    14d7:	5b                   	pop    %ebx
    14d8:	5e                   	pop    %esi
    14d9:	5f                   	pop    %edi
    14da:	5d                   	pop    %ebp
    14db:	c3                   	ret    
    14dc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  uint x;

  neg = 0;
  if(sgn && xx < 0){
    neg = 1;
    x = -xx;
    14e0:	89 d0                	mov    %edx,%eax
    14e2:	f7 d8                	neg    %eax
  int i, neg;
  uint x;

  neg = 0;
  if(sgn && xx < 0){
    neg = 1;
    14e4:	c7 45 c4 01 00 00 00 	movl   $0x1,-0x3c(%ebp)
    14eb:	eb 87                	jmp    1474 <printint+0x24>
    14ed:	8d 76 00             	lea    0x0(%esi),%esi

000014f0 <printf>:
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void
printf(int fd, char *fmt, ...)
{
    14f0:	55                   	push   %ebp
    14f1:	89 e5                	mov    %esp,%ebp
    14f3:	57                   	push   %edi
  char *s;
  int c, i, state;
  uint *ap;

  state = 0;
    14f4:	31 ff                	xor    %edi,%edi
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void
printf(int fd, char *fmt, ...)
{
    14f6:	56                   	push   %esi
    14f7:	53                   	push   %ebx
    14f8:	83 ec 3c             	sub    $0x3c,%esp
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
  for(i = 0; fmt[i]; i++){
    14fb:	8b 5d 0c             	mov    0xc(%ebp),%ebx
  char *s;
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
    14fe:	8d 45 10             	lea    0x10(%ebp),%eax
}

// Print to the given fd. Only understands %d, %x, %p, %s.
void
printf(int fd, char *fmt, ...)
{
    1501:	8b 75 08             	mov    0x8(%ebp),%esi
  char *s;
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
    1504:	89 45 d4             	mov    %eax,-0x2c(%ebp)
  for(i = 0; fmt[i]; i++){
    1507:	0f b6 13             	movzbl (%ebx),%edx
    150a:	83 c3 01             	add    $0x1,%ebx
    150d:	84 d2                	test   %dl,%dl
    150f:	75 39                	jne    154a <printf+0x5a>
    1511:	e9 c2 00 00 00       	jmp    15d8 <printf+0xe8>
    1516:	66 90                	xchg   %ax,%ax
    c = fmt[i] & 0xff;
    if(state == 0){
      if(c == '%'){
    1518:	83 fa 25             	cmp    $0x25,%edx
    151b:	0f 84 bf 00 00 00    	je     15e0 <printf+0xf0>
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1521:	8d 45 e2             	lea    -0x1e(%ebp),%eax
    1524:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    152b:	00 
    152c:	89 44 24 04          	mov    %eax,0x4(%esp)
    1530:	89 34 24             	mov    %esi,(%esp)
    c = fmt[i] & 0xff;
    if(state == 0){
      if(c == '%'){
        state = '%';
      } else {
        putc(fd, c);
    1533:	88 55 e2             	mov    %dl,-0x1e(%ebp)
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1536:	e8 77 fe ff ff       	call   13b2 <write>
    153b:	83 c3 01             	add    $0x1,%ebx
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
  for(i = 0; fmt[i]; i++){
    153e:	0f b6 53 ff          	movzbl -0x1(%ebx),%edx
    1542:	84 d2                	test   %dl,%dl
    1544:	0f 84 8e 00 00 00    	je     15d8 <printf+0xe8>
    c = fmt[i] & 0xff;
    if(state == 0){
    154a:	85 ff                	test   %edi,%edi
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
  for(i = 0; fmt[i]; i++){
    c = fmt[i] & 0xff;
    154c:	0f be c2             	movsbl %dl,%eax
    if(state == 0){
    154f:	74 c7                	je     1518 <printf+0x28>
      if(c == '%'){
        state = '%';
      } else {
        putc(fd, c);
      }
    } else if(state == '%'){
    1551:	83 ff 25             	cmp    $0x25,%edi
    1554:	75 e5                	jne    153b <printf+0x4b>
      if(c == 'd'){
    1556:	83 fa 64             	cmp    $0x64,%edx
    1559:	0f 84 31 01 00 00    	je     1690 <printf+0x1a0>
        printint(fd, *ap, 10, 1);
        ap++;
      } else if(c == 'x' || c == 'p'){
    155f:	25 f7 00 00 00       	and    $0xf7,%eax
    1564:	83 f8 70             	cmp    $0x70,%eax
    1567:	0f 84 83 00 00 00    	je     15f0 <printf+0x100>
        printint(fd, *ap, 16, 0);
        ap++;
      } else if(c == 's'){
    156d:	83 fa 73             	cmp    $0x73,%edx
    1570:	0f 84 a2 00 00 00    	je     1618 <printf+0x128>
          s = "(null)";
        while(*s != 0){
          putc(fd, *s);
          s++;
        }
      } else if(c == 'c'){
    1576:	83 fa 63             	cmp    $0x63,%edx
    1579:	0f 84 35 01 00 00    	je     16b4 <printf+0x1c4>
        putc(fd, *ap);
        ap++;
      } else if(c == '%'){
    157f:	83 fa 25             	cmp    $0x25,%edx
    1582:	0f 84 e0 00 00 00    	je     1668 <printf+0x178>
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1588:	8d 45 e6             	lea    -0x1a(%ebp),%eax
    158b:	83 c3 01             	add    $0x1,%ebx
    158e:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1595:	00 
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    1596:	31 ff                	xor    %edi,%edi
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1598:	89 44 24 04          	mov    %eax,0x4(%esp)
    159c:	89 34 24             	mov    %esi,(%esp)
    159f:	89 55 d0             	mov    %edx,-0x30(%ebp)
    15a2:	c6 45 e6 25          	movb   $0x25,-0x1a(%ebp)
    15a6:	e8 07 fe ff ff       	call   13b2 <write>
      } else if(c == '%'){
        putc(fd, c);
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
    15ab:	8b 55 d0             	mov    -0x30(%ebp),%edx
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    15ae:	8d 45 e7             	lea    -0x19(%ebp),%eax
    15b1:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    15b8:	00 
    15b9:	89 44 24 04          	mov    %eax,0x4(%esp)
    15bd:	89 34 24             	mov    %esi,(%esp)
      } else if(c == '%'){
        putc(fd, c);
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
    15c0:	88 55 e7             	mov    %dl,-0x19(%ebp)
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    15c3:	e8 ea fd ff ff       	call   13b2 <write>
  int c, i, state;
  uint *ap;

  state = 0;
  ap = (uint*)(void*)&fmt + 1;
  for(i = 0; fmt[i]; i++){
    15c8:	0f b6 53 ff          	movzbl -0x1(%ebx),%edx
    15cc:	84 d2                	test   %dl,%dl
    15ce:	0f 85 76 ff ff ff    	jne    154a <printf+0x5a>
    15d4:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
        putc(fd, c);
      }
      state = 0;
    }
  }
}
    15d8:	83 c4 3c             	add    $0x3c,%esp
    15db:	5b                   	pop    %ebx
    15dc:	5e                   	pop    %esi
    15dd:	5f                   	pop    %edi
    15de:	5d                   	pop    %ebp
    15df:	c3                   	ret    
  ap = (uint*)(void*)&fmt + 1;
  for(i = 0; fmt[i]; i++){
    c = fmt[i] & 0xff;
    if(state == 0){
      if(c == '%'){
        state = '%';
    15e0:	bf 25 00 00 00       	mov    $0x25,%edi
    15e5:	e9 51 ff ff ff       	jmp    153b <printf+0x4b>
    15ea:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    } else if(state == '%'){
      if(c == 'd'){
        printint(fd, *ap, 10, 1);
        ap++;
      } else if(c == 'x' || c == 'p'){
        printint(fd, *ap, 16, 0);
    15f0:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    15f3:	b9 10 00 00 00       	mov    $0x10,%ecx
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    15f8:	31 ff                	xor    %edi,%edi
    } else if(state == '%'){
      if(c == 'd'){
        printint(fd, *ap, 10, 1);
        ap++;
      } else if(c == 'x' || c == 'p'){
        printint(fd, *ap, 16, 0);
    15fa:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
    1601:	8b 10                	mov    (%eax),%edx
    1603:	89 f0                	mov    %esi,%eax
    1605:	e8 46 fe ff ff       	call   1450 <printint>
        ap++;
    160a:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    160e:	e9 28 ff ff ff       	jmp    153b <printf+0x4b>
    1613:	90                   	nop
    1614:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
      } else if(c == 's'){
        s = (char*)*ap;
    1618:	8b 45 d4             	mov    -0x2c(%ebp),%eax
        ap++;
    161b:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
        ap++;
      } else if(c == 'x' || c == 'p'){
        printint(fd, *ap, 16, 0);
        ap++;
      } else if(c == 's'){
        s = (char*)*ap;
    161f:	8b 38                	mov    (%eax),%edi
        ap++;
        if(s == 0)
          s = "(null)";
    1621:	b8 54 19 00 00       	mov    $0x1954,%eax
    1626:	85 ff                	test   %edi,%edi
    1628:	0f 44 f8             	cmove  %eax,%edi
        while(*s != 0){
    162b:	0f b6 07             	movzbl (%edi),%eax
    162e:	84 c0                	test   %al,%al
    1630:	74 2a                	je     165c <printf+0x16c>
    1632:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    1638:	88 45 e3             	mov    %al,-0x1d(%ebp)
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    163b:	8d 45 e3             	lea    -0x1d(%ebp),%eax
        ap++;
        if(s == 0)
          s = "(null)";
        while(*s != 0){
          putc(fd, *s);
          s++;
    163e:	83 c7 01             	add    $0x1,%edi
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1641:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1648:	00 
    1649:	89 44 24 04          	mov    %eax,0x4(%esp)
    164d:	89 34 24             	mov    %esi,(%esp)
    1650:	e8 5d fd ff ff       	call   13b2 <write>
      } else if(c == 's'){
        s = (char*)*ap;
        ap++;
        if(s == 0)
          s = "(null)";
        while(*s != 0){
    1655:	0f b6 07             	movzbl (%edi),%eax
    1658:	84 c0                	test   %al,%al
    165a:	75 dc                	jne    1638 <printf+0x148>
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    165c:	31 ff                	xor    %edi,%edi
    165e:	e9 d8 fe ff ff       	jmp    153b <printf+0x4b>
    1663:	90                   	nop
    1664:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    1668:	8d 45 e5             	lea    -0x1b(%ebp),%eax
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    166b:	31 ff                	xor    %edi,%edi
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    166d:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    1674:	00 
    1675:	89 44 24 04          	mov    %eax,0x4(%esp)
    1679:	89 34 24             	mov    %esi,(%esp)
    167c:	c6 45 e5 25          	movb   $0x25,-0x1b(%ebp)
    1680:	e8 2d fd ff ff       	call   13b2 <write>
    1685:	e9 b1 fe ff ff       	jmp    153b <printf+0x4b>
    168a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
      } else {
        putc(fd, c);
      }
    } else if(state == '%'){
      if(c == 'd'){
        printint(fd, *ap, 10, 1);
    1690:	8b 45 d4             	mov    -0x2c(%ebp),%eax
    1693:	b9 0a 00 00 00       	mov    $0xa,%ecx
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    1698:	66 31 ff             	xor    %di,%di
      } else {
        putc(fd, c);
      }
    } else if(state == '%'){
      if(c == 'd'){
        printint(fd, *ap, 10, 1);
    169b:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
    16a2:	8b 10                	mov    (%eax),%edx
    16a4:	89 f0                	mov    %esi,%eax
    16a6:	e8 a5 fd ff ff       	call   1450 <printint>
        ap++;
    16ab:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    16af:	e9 87 fe ff ff       	jmp    153b <printf+0x4b>
        while(*s != 0){
          putc(fd, *s);
          s++;
        }
      } else if(c == 'c'){
        putc(fd, *ap);
    16b4:	8b 45 d4             	mov    -0x2c(%ebp),%eax
      } else {
        // Unknown % sequence.  Print it to draw attention.
        putc(fd, '%');
        putc(fd, c);
      }
      state = 0;
    16b7:	31 ff                	xor    %edi,%edi
        while(*s != 0){
          putc(fd, *s);
          s++;
        }
      } else if(c == 'c'){
        putc(fd, *ap);
    16b9:	8b 00                	mov    (%eax),%eax
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    16bb:	c7 44 24 08 01 00 00 	movl   $0x1,0x8(%esp)
    16c2:	00 
    16c3:	89 34 24             	mov    %esi,(%esp)
        while(*s != 0){
          putc(fd, *s);
          s++;
        }
      } else if(c == 'c'){
        putc(fd, *ap);
    16c6:	88 45 e4             	mov    %al,-0x1c(%ebp)
#include "user.h"

static void
putc(int fd, char c)
{
  write(fd, &c, 1);
    16c9:	8d 45 e4             	lea    -0x1c(%ebp),%eax
    16cc:	89 44 24 04          	mov    %eax,0x4(%esp)
    16d0:	e8 dd fc ff ff       	call   13b2 <write>
          putc(fd, *s);
          s++;
        }
      } else if(c == 'c'){
        putc(fd, *ap);
        ap++;
    16d5:	83 45 d4 04          	addl   $0x4,-0x2c(%ebp)
    16d9:	e9 5d fe ff ff       	jmp    153b <printf+0x4b>
    16de:	66 90                	xchg   %ax,%ax

000016e0 <free>:
static Header base;
static Header *freep;

void
free(void *ap)
{
    16e0:	55                   	push   %ebp
  Header *bp, *p;

  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    16e1:	a1 18 1c 00 00       	mov    0x1c18,%eax
static Header base;
static Header *freep;

void
free(void *ap)
{
    16e6:	89 e5                	mov    %esp,%ebp
    16e8:	57                   	push   %edi
    16e9:	56                   	push   %esi
    16ea:	53                   	push   %ebx
    16eb:	8b 5d 08             	mov    0x8(%ebp),%ebx
  Header *bp, *p;

  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    16ee:	8b 08                	mov    (%eax),%ecx
void
free(void *ap)
{
  Header *bp, *p;

  bp = (Header*)ap - 1;
    16f0:	8d 53 f8             	lea    -0x8(%ebx),%edx
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    16f3:	39 d0                	cmp    %edx,%eax
    16f5:	72 11                	jb     1708 <free+0x28>
    16f7:	90                   	nop
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    16f8:	39 c8                	cmp    %ecx,%eax
    16fa:	72 04                	jb     1700 <free+0x20>
    16fc:	39 ca                	cmp    %ecx,%edx
    16fe:	72 10                	jb     1710 <free+0x30>
    1700:	89 c8                	mov    %ecx,%eax
free(void *ap)
{
  Header *bp, *p;

  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1702:	39 d0                	cmp    %edx,%eax
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    1704:	8b 08                	mov    (%eax),%ecx
free(void *ap)
{
  Header *bp, *p;

  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    1706:	73 f0                	jae    16f8 <free+0x18>
    1708:	39 ca                	cmp    %ecx,%edx
    170a:	72 04                	jb     1710 <free+0x30>
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
    170c:	39 c8                	cmp    %ecx,%eax
    170e:	72 f0                	jb     1700 <free+0x20>
      break;
  if(bp + bp->s.size == p->s.ptr){
    1710:	8b 73 fc             	mov    -0x4(%ebx),%esi
    1713:	8d 3c f2             	lea    (%edx,%esi,8),%edi
    1716:	39 cf                	cmp    %ecx,%edi
    1718:	74 1e                	je     1738 <free+0x58>
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
    171a:	89 4b f8             	mov    %ecx,-0x8(%ebx)
  if(p + p->s.size == bp){
    171d:	8b 48 04             	mov    0x4(%eax),%ecx
    1720:	8d 34 c8             	lea    (%eax,%ecx,8),%esi
    1723:	39 f2                	cmp    %esi,%edx
    1725:	74 28                	je     174f <free+0x6f>
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
    1727:	89 10                	mov    %edx,(%eax)
  freep = p;
    1729:	a3 18 1c 00 00       	mov    %eax,0x1c18
}
    172e:	5b                   	pop    %ebx
    172f:	5e                   	pop    %esi
    1730:	5f                   	pop    %edi
    1731:	5d                   	pop    %ebp
    1732:	c3                   	ret    
    1733:	90                   	nop
    1734:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;
  if(bp + bp->s.size == p->s.ptr){
    bp->s.size += p->s.ptr->s.size;
    1738:	03 71 04             	add    0x4(%ecx),%esi
    173b:	89 73 fc             	mov    %esi,-0x4(%ebx)
    bp->s.ptr = p->s.ptr->s.ptr;
    173e:	8b 08                	mov    (%eax),%ecx
    1740:	8b 09                	mov    (%ecx),%ecx
    1742:	89 4b f8             	mov    %ecx,-0x8(%ebx)
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    1745:	8b 48 04             	mov    0x4(%eax),%ecx
    1748:	8d 34 c8             	lea    (%eax,%ecx,8),%esi
    174b:	39 f2                	cmp    %esi,%edx
    174d:	75 d8                	jne    1727 <free+0x47>
    p->s.size += bp->s.size;
    174f:	03 4b fc             	add    -0x4(%ebx),%ecx
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
    1752:	a3 18 1c 00 00       	mov    %eax,0x1c18
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    p->s.size += bp->s.size;
    1757:	89 48 04             	mov    %ecx,0x4(%eax)
    p->s.ptr = bp->s.ptr;
    175a:	8b 53 f8             	mov    -0x8(%ebx),%edx
    175d:	89 10                	mov    %edx,(%eax)
  } else
    p->s.ptr = bp;
  freep = p;
}
    175f:	5b                   	pop    %ebx
    1760:	5e                   	pop    %esi
    1761:	5f                   	pop    %edi
    1762:	5d                   	pop    %ebp
    1763:	c3                   	ret    
    1764:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
    176a:	8d bf 00 00 00 00    	lea    0x0(%edi),%edi

00001770 <malloc>:
  return freep;
}

void*
malloc(uint nbytes)
{
    1770:	55                   	push   %ebp
    1771:	89 e5                	mov    %esp,%ebp
    1773:	57                   	push   %edi
    1774:	56                   	push   %esi
    1775:	53                   	push   %ebx
    1776:	83 ec 1c             	sub    $0x1c,%esp
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    1779:	8b 45 08             	mov    0x8(%ebp),%eax
  if((prevp = freep) == 0){
    177c:	8b 1d 18 1c 00 00    	mov    0x1c18,%ebx
malloc(uint nbytes)
{
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    1782:	8d 48 07             	lea    0x7(%eax),%ecx
    1785:	c1 e9 03             	shr    $0x3,%ecx
  if((prevp = freep) == 0){
    1788:	85 db                	test   %ebx,%ebx
malloc(uint nbytes)
{
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
    178a:	8d 71 01             	lea    0x1(%ecx),%esi
  if((prevp = freep) == 0){
    178d:	0f 84 9b 00 00 00    	je     182e <malloc+0xbe>
    1793:	8b 13                	mov    (%ebx),%edx
    1795:	8b 7a 04             	mov    0x4(%edx),%edi
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    if(p->s.size >= nunits){
    1798:	39 fe                	cmp    %edi,%esi
    179a:	76 64                	jbe    1800 <malloc+0x90>
    179c:	8d 04 f5 00 00 00 00 	lea    0x0(,%esi,8),%eax
morecore(uint nu)
{
  char *p;
  Header *hp;

  if(nu < 4096)
    17a3:	bb 00 80 00 00       	mov    $0x8000,%ebx
    17a8:	89 45 e4             	mov    %eax,-0x1c(%ebp)
    17ab:	eb 0e                	jmp    17bb <malloc+0x4b>
    17ad:	8d 76 00             	lea    0x0(%esi),%esi
  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
  if((prevp = freep) == 0){
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    17b0:	8b 02                	mov    (%edx),%eax
    if(p->s.size >= nunits){
    17b2:	8b 78 04             	mov    0x4(%eax),%edi
    17b5:	39 fe                	cmp    %edi,%esi
    17b7:	76 4f                	jbe    1808 <malloc+0x98>
    17b9:	89 c2                	mov    %eax,%edx
        p->s.size = nunits;
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
    17bb:	3b 15 18 1c 00 00    	cmp    0x1c18,%edx
    17c1:	75 ed                	jne    17b0 <malloc+0x40>
morecore(uint nu)
{
  char *p;
  Header *hp;

  if(nu < 4096)
    17c3:	8b 45 e4             	mov    -0x1c(%ebp),%eax
    17c6:	81 fe 00 10 00 00    	cmp    $0x1000,%esi
    17cc:	bf 00 10 00 00       	mov    $0x1000,%edi
    17d1:	0f 43 fe             	cmovae %esi,%edi
    17d4:	0f 42 c3             	cmovb  %ebx,%eax
    nu = 4096;
  p = sbrk(nu * sizeof(Header));
    17d7:	89 04 24             	mov    %eax,(%esp)
    17da:	e8 3b fc ff ff       	call   141a <sbrk>
  if(p == (char*)-1)
    17df:	83 f8 ff             	cmp    $0xffffffff,%eax
    17e2:	74 18                	je     17fc <malloc+0x8c>
    return 0;
  hp = (Header*)p;
  hp->s.size = nu;
    17e4:	89 78 04             	mov    %edi,0x4(%eax)
  free((void*)(hp + 1));
    17e7:	83 c0 08             	add    $0x8,%eax
    17ea:	89 04 24             	mov    %eax,(%esp)
    17ed:	e8 ee fe ff ff       	call   16e0 <free>
  return freep;
    17f2:	8b 15 18 1c 00 00    	mov    0x1c18,%edx
      }
      freep = prevp;
      return (void*)(p + 1);
    }
    if(p == freep)
      if((p = morecore(nunits)) == 0)
    17f8:	85 d2                	test   %edx,%edx
    17fa:	75 b4                	jne    17b0 <malloc+0x40>
        return 0;
    17fc:	31 c0                	xor    %eax,%eax
    17fe:	eb 20                	jmp    1820 <malloc+0xb0>
  if((prevp = freep) == 0){
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    if(p->s.size >= nunits){
    1800:	89 d0                	mov    %edx,%eax
    1802:	89 da                	mov    %ebx,%edx
    1804:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
      if(p->s.size == nunits)
    1808:	39 fe                	cmp    %edi,%esi
    180a:	74 1c                	je     1828 <malloc+0xb8>
        prevp->s.ptr = p->s.ptr;
      else {
        p->s.size -= nunits;
    180c:	29 f7                	sub    %esi,%edi
    180e:	89 78 04             	mov    %edi,0x4(%eax)
        p += p->s.size;
    1811:	8d 04 f8             	lea    (%eax,%edi,8),%eax
        p->s.size = nunits;
    1814:	89 70 04             	mov    %esi,0x4(%eax)
      }
      freep = prevp;
    1817:	89 15 18 1c 00 00    	mov    %edx,0x1c18
      return (void*)(p + 1);
    181d:	83 c0 08             	add    $0x8,%eax
    }
    if(p == freep)
      if((p = morecore(nunits)) == 0)
        return 0;
  }
}
    1820:	83 c4 1c             	add    $0x1c,%esp
    1823:	5b                   	pop    %ebx
    1824:	5e                   	pop    %esi
    1825:	5f                   	pop    %edi
    1826:	5d                   	pop    %ebp
    1827:	c3                   	ret    
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    if(p->s.size >= nunits){
      if(p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
    1828:	8b 08                	mov    (%eax),%ecx
    182a:	89 0a                	mov    %ecx,(%edx)
    182c:	eb e9                	jmp    1817 <malloc+0xa7>
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
  if((prevp = freep) == 0){
    base.s.ptr = freep = prevp = &base;
    182e:	c7 05 18 1c 00 00 1c 	movl   $0x1c1c,0x1c18
    1835:	1c 00 00 
    base.s.size = 0;
    1838:	ba 1c 1c 00 00       	mov    $0x1c1c,%edx
  Header *p, *prevp;
  uint nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
  if((prevp = freep) == 0){
    base.s.ptr = freep = prevp = &base;
    183d:	c7 05 1c 1c 00 00 1c 	movl   $0x1c1c,0x1c1c
    1844:	1c 00 00 
    base.s.size = 0;
    1847:	c7 05 20 1c 00 00 00 	movl   $0x0,0x1c20
    184e:	00 00 00 
    1851:	e9 46 ff ff ff       	jmp    179c <malloc+0x2c>
    1856:	66 90                	xchg   %ax,%ax
    1858:	66 90                	xchg   %ax,%ax
    185a:	66 90                	xchg   %ax,%ax
    185c:	66 90                	xchg   %ax,%ax
    185e:	66 90                	xchg   %ax,%ax

00001860 <uacquire>:
#include "uspinlock.h"
#include "x86.h"

void
uacquire(struct uspinlock *lk)
{
    1860:	55                   	push   %ebp
xchg(volatile uint *addr, uint newval)
{
  uint result;

  // The + in "+m" denotes a read-modify-write operand.
  asm volatile("lock; xchgl %0, %1" :
    1861:	b9 01 00 00 00       	mov    $0x1,%ecx
    1866:	89 e5                	mov    %esp,%ebp
    1868:	8b 55 08             	mov    0x8(%ebp),%edx
    186b:	90                   	nop
    186c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
    1870:	89 c8                	mov    %ecx,%eax
    1872:	f0 87 02             	lock xchg %eax,(%edx)
  // The xchg is atomic.
  while(xchg(&lk->locked, 1) != 0)
    1875:	85 c0                	test   %eax,%eax
    1877:	75 f7                	jne    1870 <uacquire+0x10>
    ;

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that the critical section's memory
  // references happen after the lock is acquired.
  __sync_synchronize();
    1879:	0f ae f0             	mfence 
}
    187c:	5d                   	pop    %ebp
    187d:	c3                   	ret    
    187e:	66 90                	xchg   %ax,%ax

00001880 <urelease>:

void urelease (struct uspinlock *lk) {
    1880:	55                   	push   %ebp
    1881:	89 e5                	mov    %esp,%ebp
    1883:	8b 45 08             	mov    0x8(%ebp),%eax
  __sync_synchronize();
    1886:	0f ae f0             	mfence 

  // Release the lock, equivalent to lk->locked = 0.
  // This code can't use a C assignment, since it might
  // not be atomic. A real OS would use C atomics here.
  asm volatile("movl $0, %0" : "+m" (lk->locked) : );
    1889:	c7 00 00 00 00 00    	movl   $0x0,(%eax)
}
    188f:	5d                   	pop    %ebp
    1890:	c3                   	ret    
