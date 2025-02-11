import pygame
import math

# Constants
WIDTH, HEIGHT = 800, 600
BALL_RADIUS = 10
BALL_SPEED = 2
TRIANGLE_ROTATION_SPEED = 0.01

# Colors
BLUE = (0, 0, 255)
WHITE = (255, 255, 255)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

# Triangle vertices (initially upright equilateral)
def get_triangle_vertices(center, size, angle):
    h = size * math.sqrt(3) / 2  # Height of equilateral triangle
    points = [
        (center[0] + size * math.cos(angle), center[1] + size * math.sin(angle)),
        (center[0] + size * math.cos(angle + 2 * math.pi / 3), center[1] + size * math.sin(angle + 2 * math.pi / 3)),
        (center[0] + size * math.cos(angle - 2 * math.pi / 3), center[1] + size * math.sin(angle - 2 * math.pi / 3)),
    ]
    return points

# Ball properties
ball_pos = [WIDTH // 2, HEIGHT // 2]
ball_vel = [BALL_SPEED, BALL_SPEED]

# Triangle properties
triangle_center = (WIDTH // 2, HEIGHT // 2)
triangle_size = 200
triangle_angle = 0

def point_in_triangle(p, a, b, c):
    """Check if point p is inside the triangle formed by (a, b, c)."""
    def sign(p1, p2, p3):
        return (p1[0] - p3[0]) * (p2[1] - p3[1]) - (p2[0] - p3[0]) * (p1[1] - p3[1])
    
    d1 = sign(p, a, b)
    d2 = sign(p, b, c)
    d3 = sign(p, c, a)
    
    has_neg = (d1 < 0) or (d2 < 0) or (d3 < 0)
    has_pos = (d1 > 0) or (d2 > 0) or (d3 > 0)
    
    return not (has_neg and has_pos)

running = True
while running:
    screen.fill(WHITE)
    
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    
    # Rotate triangle
    triangle_angle += TRIANGLE_ROTATION_SPEED
    triangle_vertices = get_triangle_vertices(triangle_center, triangle_size, triangle_angle)
    
    # Move ball
    new_pos = [ball_pos[0] + ball_vel[0], ball_pos[1] + ball_vel[1]]
    
    # Check for collisions with triangle boundary
    if not point_in_triangle(new_pos, *triangle_vertices):
        ball_vel[0] = -ball_vel[0]
        ball_vel[1] = -ball_vel[1]
    else:
        ball_pos = new_pos
    
    # Draw triangle
    pygame.draw.polygon(screen, (0, 0, 0), triangle_vertices, 2)
    
    # Draw ball
    pygame.draw.circle(screen, BLUE, (int(ball_pos[0]), int(ball_pos[1])), BALL_RADIUS)
    
    pygame.display.flip()
    clock.tick(60)

pygame.quit()