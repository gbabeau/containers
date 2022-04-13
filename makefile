NAME = ft_container
NAME2 = std_container

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98 -pedantic #-g -fsanitize=address #-D NAME="ft" #--std=c++98 -pedantic
STDFLAG = -D M_NAMESPACE=1
MFLAG = -D M_NAMESPACE=0
SRCS = main.cpp
OBJS_DIR = obj/
OBJS_DIRSTD =  objstd/
OBJ = $(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
OBJ_STD = $(addprefix $(OBJS_DIRSTD), $(SRCS:%.cpp=%.o))
all: $(NAME) $(NAME2)
$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $(MFLAG) -o $@ -c $<
$(OBJS_DIRSTD)%.o: %.cpp
	mkdir -p $(OBJS_DIRSTD)
	$(CXX) $(CXXFLAGS) $(STDFLAG) -o $@ -c $<
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(MFLAG) $(OBJ) -o $(NAME)
$(NAME2) : $(OBJ_STD)
	$(CXX) $(CXXFLAGS) $(STDFLAG) $(OBJ_STD) -o $(NAME2)
clean:
	rm -rf $(OBJS) objs
fclean:
	rm -rf $(NAME) $(NAME2) $(OBJS) $(OBJS_DIR) $(OBJS_DIRSTD)
re: fclean
	make all
