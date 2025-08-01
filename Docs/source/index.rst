.. SerialIO documentation master file, created by
   sphinx-quickstart on Sat Mar 29 19:38:49 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.
.. toctree::
   :maxdepth: 2
   :caption: Contents:
   :hidden:

   installation
   tutorial
   example
   apidocumentation 

DriveMaster
===========

.. _mainpage:

DriveMaster is a common library designed to simplify the implementation of RC protocol decoding in Arduino projects. It provides a modular and extensible architecture that allows for easy integration of various RC protocols.

Supported Protocol
------------------

- `DShot`_

DShot
------

Frame Structure
^^^^^^^^^^^^^^^

The DShot frame consists of 16 bits and follows a specific structure:

- **Throttle**: 11 bits representing throttle values ranging from 48 to 2047.
- **Telemetry Request**: 1 bit indicating whether telemetry data is requested.
- **CRC**: 4 bits for error checking using a cyclic redundancy check.

DShot Versions and Bitrates
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Different versions of DShot support varying bitrates and durations for high and low signal times:

.. list-table::
   :header-rows: 1

   * - DShot Version
     - Bitrate (bps)
     - T1H (µs)
     - T0H (µs)
     - Bit Length (µs)
     - Frame Length (µs)
   * - DShot150
     - 150,000
     - 5.00
     - 2.50
     - 6.67
     - 106.72
   * - DShot300
     - 300,000
     - 2.50
     - 1.25
     - 3.33
     - 53.28
   * - DShot600
     - 600,000
     - 1.25
     - 0.625
     - 1.67
     - 26.72
   * - DShot1200
     - 1,200,000
     - 0.625
     - 0.313
     - 0.83
     - 13.28

Getting Started
----------------

- `Installation <installation.html>`_
- `Tutorial <tutorial.html>`_
- `Examples <example.html>`_

License
-------

.. image:: https://www.gnu.org/graphics/gplv3-or-later.svg
   :target: https://www.gnu.org/licenses/gpl-3.0.en.html
   :alt: GPL‑3.0‑or‑later
   :width: 160

This library is distributed under the `GNU General Public License v3.0 or later <https://www.gnu.org/licenses/gpl-3.0.en.html>`_.