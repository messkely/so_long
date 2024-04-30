#include "../include/so_long.h"

#define WIDTH 2048
#define HEIGHT 2048

static mlx_image_t *image = NULL;
static mlx_texture_t *texture = NULL;

// Function to handle errors
void ft_error(void)
{
    puts(mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}
void ft_hook(void *mlx);
// Function to initialize player texture
void player(void *mlx)
{
    if (!texture)
    {
        texture = mlx_load_png("mandatory/skeleton.png");
        if (!texture)
            ft_error();
    }

    // Delete previous image if exists
    if (image)
        mlx_delete_image(mlx, image);

    // Create new image
    image = mlx_new_image(mlx, 128, 128);
    if (!image)
        ft_error();

    // Convert texture to image
    image = mlx_texture_to_image(mlx, texture);
    if (!image)
        ft_error();

    // Draw image at initial position (0, 0)
    mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
}

// Function to handle movement of the player
void ft_hook(void *mlx)
{
    // Check for key presses to control player movement
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		mlx_image_to_window(mlx, image, image->instances[0].x, image->instances[0].y);
	}   
    if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		image->instances[0].y -= 5;
		mlx_image_to_window(mlx, image, image->instances[0].x, image->instances[0].y);
	}
        
    if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
        {
		image->instances[0].y += 5;
		mlx_image_to_window(mlx, image, image->instances[0].x, image->instances[0].y);
	}
    if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
        {
		image->instances[0].x -= 5;
		mlx_image_to_window(mlx, image, image->instances[0].x, image->instances[0].y);
	}
    if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
        {
		image->instances[0].x += 5;
		mlx_image_to_window(mlx, image, image->instances[0].x, image->instances[0].y);
	}
    if (mlx_is_key_down(mlx, MLX_KEY_DELETE))
        mlx_delete_image(mlx, image);
}

// Main function
int32_t main(void)
{
    mlx_t *mlx;

    // Initialize MLX
    mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (!mlx)
        ft_error();

    printf("\n HHH \n");

    // Set up loop hooks for player movement and updating
    mlx_loop_hook(mlx, player, mlx);

    // Start MLX event loop
    mlx_loop(mlx);

    // Cleanup
    mlx_delete_image(mlx, image);
    mlx_delete_texture(texture);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
