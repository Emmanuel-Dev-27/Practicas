import markdown

# Create a markdown string
md_content = """
# Título

Este es un archivo markdown de ejemplo.

## Sección 1

- Elemento 1
- Elemento 2

## Sección 2

Aquí hay un [enlace](https://www.example.com).
"""

# Write the markdown string to a file
with open('example.md', 'w', encoding='utf-8') as f:
    f.write(md_content)

if __name__ == "__main__":
    # Append more content to the markdown file
    additional_content = """
    ## Sección 3

    Este es contenido adicional.
    """

    with open('example.md', 'a', encoding='utf-8') as f:
        f.write(additional_content)
        
        
        
        # Convert markdown file to HTML
        with open('example.md', 'r', encoding='utf-8') as f:
            md_text = f.read()
            html = markdown.markdown(md_text)

        # Write the HTML to a new file
        with open('example.html', 'w', encoding='utf-8') as f:
            f.write(html)