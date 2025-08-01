import subprocess

subprocess.call('cd ../.. ; doxygen', shell=True)

# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "DriveMaster"
copyright = "2025, Witty-Wizard"
author = "Witty-Wizard"
release = "0.0.3"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ["sphinx.ext.autodoc", "sphinx.ext.viewcode", "breathe", "sphinx_copybutton"]

templates_path = ["_templates"]
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]

# -- Breathe configurations --------------------------------------------------
# Path to the generated Doxygen XML files
breathe_projects = {"DriveMaster": "../xml"}
breathe_default_project = "DriveMaster"

# -- Github button -----------------------------------------------------------

html_theme_options = {
    "style_external_links": True,  # Adds an external link icon
    "navigation_depth": 4,
    "prev_next_buttons_location": "bottom",
    "collapse_navigation": False,
    "sticky_navigation": True,
}

html_context = {
    "display_github": True,
    "github_user": "Witty-Wizard",
    "github_repo": "DriveMaster",
    "github_version": "main",
    "conf_py_path": "/Docs/source/",  # Adjust based on repo structure
}
