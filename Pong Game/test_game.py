import pygame

pygame.init()
pygame.mixer.init()
 
# setting up the screen
width, height = (800,600)
window = pygame.display.set_mode((width, height))
window = pygame.display.set_mode((width, height), pygame.RESIZABLE)
pygame.display.set_caption("The pong game")
SCORE_FONT = pygame.font.SysFont("comicsans", 50)


# dimensions
PADDLE_HEIGHT= 110
PADDLE_WIDTH= 10
ball_radius=8
WINNING_SCORE= 10

# setting the FPS (frames per seconed)
clock= pygame.time.Clock()
FPS= 70

main_menu_background=pygame.image.load("instuctions_background.jpg")
main_menu_background= pygame.transform.scale(main_menu_background,(width,height))

pad_hit_sound=pygame.mixer.Sound("mixkit-ball-bouncing-in-the-ground-2077.wav")
background_music="The Levitated.mp3"
goal_scored_sound = pygame.mixer.Sound("GOAL.MP3")

# making the instruction screen
def instruction_screen():
    instruction_active = True # This variable controls whether the instruction screen should be displayed.
    while instruction_active: # Starts a while loop that runs as long as instruction_active is True.
        for event in pygame.event.get(): # This iterates through the list of events that Pygame detects.
            if event.type == pygame.QUIT: # to quit the game if the window is closed
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN: # to check if is key pressed 
                if event.key == pygame.K_m: # to check if the key that was pressed is "m"
                    instruction_active = False  # Close instructions when "M" is pressed
                

        instructions_img = pygame.image.load("instuctions_background.jpg") # to load image 
        instructions_img= pygame.transform.scale(instructions_img,(width,height)) # to make image fit w and h
        window.blit(instructions_img,(0,0)) # to draw the image in the specif coardinates

        font = pygame.font.SysFont("comic sans", 20)
        instructions = [
            "Welcome to The Pong Game!",
            "Player 1:",
            "Use 'W' to move up,'S' to move down.",
            "Player 2:",
            "Use 'UP ARROW' to move up,'DOWN ARROW' to move down.",
            "THE FIRST PLAYER TO SCORE 10 GOALS WINS",
            "Press 'M' to return to the Main Menu."
        ]
        y_offset = 70 # to determine the position of the text on the y- axis
        for line in instructions:
            text = font.render(line, True, "black")
            window.blit(text, (100, y_offset))
            y_offset += 70

        pygame.display.update()

# Modify menu_display() to include an instruction option
def menu_display():
    font1 = pygame.font.SysFont("Comic Sans", 40)
    font2 = pygame.font.SysFont("comic sans", 25)
    Title = font1.render("THE PONG GAME", True, "black",)
    Start = font2.render("Press 'SPACE' to start", True, "black")
    Instruction = font2.render("Press 'I' for Instructions", True, "black",)
    quit_game=font2.render("Press 'Q' to quit game",True,"black")
    window.blit(main_menu_background,(0,0))
    window.blit(Title, (220, 160)) # to display "THE PONG GAME" at the given x and y 
    window.blit(Start, (250, 280)) # to display "Press 'SPACE' to start" at the given x and y 
    window.blit(Instruction, (250, 330)) # to display "Press 'I' for Instructions" at the given x and y 
    window.blit(quit_game,(250,380)) # to display "Press 'Q' to quit game and return to desktop" at the given x and y
    
    pygame.display.update()



# Modify main_menu() to handle the instruction screen display
def main_menu():
    global paused
    width, height = (800,600)
    window = pygame.display.set_mode((width, height))
    running = True
    instruction_active = False

    while running:
        for event in pygame.event.get(): # Iterates through the list of events that Pygame detects
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN: 
                if event.key == pygame.K_i and not instruction_active: # Display instructions when "I" is pressed and check if instructions are false
                    instruction_screen() # calls the instructions function 
                elif event.key == pygame.K_SPACE:# Start the game on spacebar press
                    paused=False # Reset the paused state when returning to the main menu
                    return "game" 
                elif event.key== pygame.K_q:# to quit game when q is pressed
                    pygame.quit 
                    quit()
                

        menu_display()
        pygame.display.update()




# creating the paddeles
class paddles:
    color="black"
    pad_speed= 10

    def __init__(self, x, y,height,width): # to make the properties of the paddale
        self.init_x = x  # Store initial x position
        self.init_y = y  # Store initial y position
        self.x=x
        self.y=y
        self.height= height
        self.width= width

    def draw(self,window):
        pygame.draw.rect(window,self.color,(self.x,self.y,self.width,self.height))

    def move(self, up):
        if up:
            self.y -= self.pad_speed
        else:
            self.y += self.pad_speed

        self.y = max(0, min(self.y, height - self.height))

    def reset(self):
        self.x=self.init_x
        self.y=self.init_y




def moving_the_pads(keys,first_pad,seconed_pad):
    if keys[pygame.K_w]:
        first_pad.move(up=True)
    elif keys[pygame.K_s]:
        first_pad.move(up=False)
        
    if keys[pygame.K_UP]:
        seconed_pad.move(up=True)
    elif keys[pygame.K_DOWN]:
        seconed_pad.move(up=False)




# creating the ball
class ball:
    color="black"
    ball_speed=12
    def __init__(self,x,y,radius):
        self.x=x
        self.y=y
        self.radius= radius
        self.x_vel=self.ball_speed # to let the ball hit directly the pad 
        self.y_vel= 0


    def move(self): # moving the ball
        self.x+= self.x_vel
        self.y+= self.y_vel
    
        
    def draw(self,window): # drawing the ball
        pygame.draw.circle(window,self.color,(self.x,self.y),self.radius)

    
    def reset(self, x, y):
        self.x = x
        self.y = y
        self.x_vel = self.ball_speed
        self.y_vel = 0



def collision(the_ball, first_pad, seconed_pad):
    if the_ball.y + the_ball.radius >= height:
        the_ball.y_vel *= -1
        pad_hit_sound.set_volume(1.0)
        pad_hit_sound.play()
    elif the_ball.y - the_ball.radius <= 0:
        the_ball.y_vel *= -1
        pad_hit_sound.set_volume(1.1)
        pad_hit_sound.play()

    if the_ball.x_vel < 0:
        if the_ball.y >= first_pad.y and the_ball.y <= first_pad.y + first_pad.height:
            if the_ball.x - the_ball.radius <= first_pad.x + first_pad.width:
                the_ball.x_vel *= -1
                pad_hit_sound.set_volume(1.1)
                pad_hit_sound.play()

                middle_y = first_pad.y + first_pad.height / 2
                difference_in_y = middle_y - the_ball.y
                reduction_factor = (first_pad.height / 2) / the_ball.ball_speed
                y_vel = difference_in_y / reduction_factor
                the_ball.y_vel = -1 * y_vel

    else:
        if the_ball.y >= seconed_pad.y and the_ball.y <= seconed_pad.y + seconed_pad.height:
            if the_ball.x + the_ball.radius >= seconed_pad.x:
                the_ball.x_vel *= -1
                pad_hit_sound.set_volume(1.1)
                pad_hit_sound.play()

                middle_y = seconed_pad.y + seconed_pad.height / 2
                difference_in_y = middle_y - the_ball.y
                reduction_factor = (seconed_pad.height / 2) / the_ball.ball_speed
                y_vel = difference_in_y / reduction_factor
                the_ball.y_vel = -1 * y_vel


def display_goal_message(window, text):
    font_goal = pygame.font.SysFont("comic sans", 70)
    text_surface = font_goal.render(text, True, "red")
    text_rect = text_surface.get_rect(center=(width // 2, height // 2))
    window.blit(text_surface, text_rect)
    pygame.display.update()
    pygame.time.delay(1200) 

def update_scores(left_score, right_score, the_ball, width,first_pad,seconed_pad):
    won = False
    win_text = ""
    if the_ball.x < 0:
        right_score += 1
        the_ball.x = width // 2  # Reset the ball position after scoring
        the_ball.y = height // 2
        the_ball.x_vel = -the_ball.x_vel  # Reverse ball direction after scoring
        the_ball.y_vel = 0
        goal_scored_sound.set_volume(1.4)
        goal_scored_sound.play()
        goal_message= "GOAL!"
        display_goal_message(window,goal_message)
        first_pad.reset()
        seconed_pad.reset()
        
    elif the_ball.x > width:
        left_score += 1
        the_ball.x = width // 2  # Reset the ball position after scoring
        the_ball.y = height // 2
        the_ball.x_vel = -the_ball.x_vel  # Reverse ball direction after scoring
        the_ball.y_vel = 0
        goal_scored_sound.set_volume(1.4)
        goal_scored_sound.play()
        goal_message= "GOAL!"
        display_goal_message(window,goal_message)
        first_pad.reset()
        seconed_pad.reset()


    if left_score >= WINNING_SCORE:
        won = True
        win_text = "FIRST PLAYER WON!!!"
    elif right_score >= WINNING_SCORE:
        won = True
        win_text = "SECONED PLAYER WON!!!"

    if won:
        left_score = 0
        right_score = 0    

    return left_score, right_score,won,win_text


# to draw elements on the screen
def draw(window,paddles,the_ball,left_score,right_score):
    window.fill("white")
    for paddle in paddles: # to draw each paddle in paddles
        paddle.draw(window)
    the_ball.draw(window)# to draw the ball

    left_score_text = SCORE_FONT.render(f"{left_score}", 1, "black")
    right_score_text = SCORE_FONT.render(f"{right_score}", 1, "black")

    window.blit(left_score_text, (width // 4 - left_score_text.get_width() // 2, 20))
    window.blit(right_score_text, (width * (3 / 4) - right_score_text.get_width() // 2, 20))

    # the dashed line
    dash_width = 5
    dash_height = 20
    dash_gap = 5
    dash_y = 0
    
    while dash_y < height: # Loop that continues until the y-coordinate of the dashes reaches the bottom of the screen
        pygame.draw.rect(window, "black", (width // 2 - dash_width // 2, dash_y, dash_width, dash_height))
        dash_y += dash_height + dash_gap


    pygame.display.update()


def pause_music(): # his function pauses the currently playing music
    pygame.mixer.music.pause()

def resume_music(): # his function resume the music
    pygame.mixer.music.unpause()

def reset_music():
    pygame.mixer.music.rewind()


def toggle_pause():
    global paused
    paused = not paused
    if paused:
        pause_music()
    else:
        resume_music()

def play_again_screen(): # function to play again
    play_again_active = True
    while play_again_active:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_p:  # Press P to play again
                    play_again_active = False
                if event.key==pygame.K_q:
                    pygame.quit()
                    quit()
        window.fill("white")
        font = pygame.font.SysFont("comic sans", 30)
        play_again_text = font.render("Press 'P' to play again", True, "black")
        quit_txt=font.render("Press 'Q' to quit game",True,"black")
        window.blit(play_again_text, (width // 2 - play_again_text.get_width() // 2, height // 2 - 20 ))
        window.blit(quit_txt,(width//2 - quit_txt.get_width()//2,height//2 +20 ))
        pygame.display.update()


def main_loop(won=None):
    win_text=""

    pygame.mixer.music.load(background_music)
    pygame.mixer.music.play(-1)
    pygame.mixer.music.set_volume(0.5)


    global paused  # Global variable to track if the game is paused
    running = True  # Flag for the game loop
    font_p = pygame.font.SysFont("Comic sans", 50)  # Font for "game is paused" txt
    r_font = pygame.font.SysFont("Comic sans", 30)  # Font for "press 'R' to return" txt
    paused_txt = font_p.render("GAME IS PUASED", True, "black")  # Render the "game is paused" txt
    r_txt = r_font.render("press 'R' to return to main menu", True, "Black")  # Render the "press 'R' to return" txt

    first_pad=paddles(10,height//2-PADDLE_HEIGHT/2,PADDLE_HEIGHT,PADDLE_WIDTH) # defining the first player pad
    seconed_pad=paddles(width-10-PADDLE_WIDTH,height//2-100/2,PADDLE_HEIGHT,PADDLE_WIDTH) # defining the seconed player pad
    the_ball=ball(width//2,height//2,ball_radius)


    left_score = 0
    right_score = 0

    while running:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                running= False
                break
            elif event.type == pygame.KEYDOWN:
                if event.key== pygame.K_ESCAPE: # to pause the game when "esc" is pressed
                    toggle_pause()
                elif event.key == pygame.K_r: # Return to main menu if 'r' key is pressed
                    return


        if not paused:
            keys=pygame.key.get_pressed()
            moving_the_pads(keys,first_pad,seconed_pad)
            the_ball.move()
            collision(the_ball,first_pad,seconed_pad)
            # Drawing game elements
            draw(window,[first_pad,seconed_pad],the_ball,left_score,right_score) 
        # Inside the main game loop where you handle the game logic
        

        if paused:  # Displaying pause text when the game is paused
            window.fill("white")
            paused_text_x = width // 2 - paused_txt.get_width() // 2 # Calculate the X and Y coordinates to center the "game is paused" txt
            paused_text_y = height // 2 - paused_txt.get_height() // 2
            window.blit(paused_txt, (paused_text_x, paused_text_y)) # Display the "game is paused" txt

        # Display "press 'R' to return" text under "game is paused" text
            return_text_x = width // 2 - r_txt.get_width() // 2  # Calculate the X and Y coordinates for the "press 'R' to return" txt
            return_text_y = paused_text_y + paused_txt.get_height() + 20  # Set a vertical gap of 20 pixels
            window.blit(r_txt, (return_text_x, return_text_y)) # Display the "press 'R' to return" text below the "game is paused" txt
        left_score, right_score,won,win_text = update_scores(left_score, right_score, the_ball, width,first_pad,seconed_pad)

        if won:
            the_ball.reset(width//2,height//2)
            text = SCORE_FONT.render(win_text, 1, "blue")
            window.fill("white")
            window.blit(text, (width // 2 - text.get_width() // 2, height // 2))
            pause_music()
            pygame.display.update()
            pygame.time.delay(4000) # 4 secondes
            play_again_screen()
            reset_music()
            resume_music()


        pygame.display.update()  # Update the display
        
      
    pygame.quit()



if __name__ == "__main__":
    running_game = True

    while running_game:
        action = main_menu()

        if action == "game":
            main_loop()
        elif action == "exit":
            running_game = False #  If the player chooses to exit the game, 
            #it sets running_game to False, which will exit the while loop, effectively stopping the game loop.

    pygame.quit()

