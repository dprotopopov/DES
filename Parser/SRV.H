#ifndef __SRV_H
#define __SRV_H

#define DECLARE_SERVER(Server)				\
	extern char Server[];					\
	// DECLARE_SERVER

#define IMPLEMENT_SERVER(Server, Name)		\
  char Server[] = Name;						\
  // IMPLEMENT_SERVER

#define DECLARE_SERVICE(Service)			\
	extern char Service[];					\
	// DECLARE_SERVICE

#define IMPLEMENT_SERVICE(Service, Name)	\
  char Service[] = Name;					\
  // IMPLEMENT_SERVICE

#endif // __SRV_H