/* LinkedHashSet.java -- a set backed by a LinkedHashMap, for linked
   list traversal.
   Copyright (C) 2001 Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA.

As a special exception, if you link this library with other files to
produce an executable, this library does not by itself cause the
resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why the
executable file might be covered by the GNU General Public License. */


package java.util;

import java.io.Serializable;

/**
 * This class provides a hashtable-backed implementation of the
 * Set interface, with predictable traversal order.
 * <p>
 *
 * It uses a hash-bucket approach; that is, hash collisions are handled
 * by linking the new node off of the pre-existing node (or list of
 * nodes).  In this manner, techniques such as linear probing (which
 * can cause primary clustering) and rehashing (which does not fit very
 * well with Java's method of precomputing hash codes) are avoided.  In
 * addition, this maintains a doubly-linked list which tracks insertion
 * order.  Note that the insertion order is not modified if an
 * <code>add</code> simply reinserts an element in the set.
 * <p>
 *
 * One of the nice features of tracking insertion order is that you can
 * copy a set, and regardless of the implementation of the original,
 * produce the same results when iterating over the copy.  This is possible
 * without needing the overhead of <code>TreeSet</code>.
 * <p>
 *
 * Under ideal circumstances (no collisions), LinkedHashSet offers O(1) 
 * performance on most operations.  In the worst case (all elements map
 * to the same hash code -- very unlikely), most operations are O(n).
 * <p>
 *
 * LinkedHashSet accepts the null entry.  It is not synchronized, so if
 * you need multi-threaded access, consider using:<br>
 * <code>Set s = Collections.synchronizedSet(new LinkedHashSet(...));</code>
 * <p>
 *
 * The iterators are <i>fail-fast</i>, meaning that any structural
 * modification, except for <code>remove()</code> called on the iterator
 * itself, cause the iterator to throw a
 * {@link ConcurrentModificationException} rather than exhibit
 * non-deterministic behavior.
 *
 * @author Eric Blake <ebb9@email.byu.edu>
 * @see Object#hashCode()
 * @see Collection
 * @see Set
 * @see HashSet
 * @see TreeSet
 * @see Collections#synchronizedSet(Set)
 * @since 1.4
 * @status updated to 1.4
 */
public class LinkedHashSet extends HashSet
  implements Set, Cloneable, Serializable
{
  /**
   * Compatible with JDK 1.4.
   */
  private static final long serialVersionUID = -2851667679971038690L;

  /**
   * Construct a new, empty HashSet whose backing HashMap has the default
   * capacity (11) and loadFacor (0.75).
   */
  public LinkedHashSet()
  {
    super();
  }

  /**
   * Construct a new, empty HashSet whose backing HashMap has the supplied
   * capacity and the default load factor (0.75).
   *
   * @param initialCapacity the initial capacity of the backing HashMap
   * @throws IllegalArgumentException if the capacity is negative
   */
  public LinkedHashSet(int initialCapacity)
  {
    super(initialCapacity);
  }

  /**
   * Construct a new, empty HashSet whose backing HashMap has the supplied
   * capacity and load factor.
   *
   * @param initialCapacity the initial capacity of the backing HashMap
   * @param loadFactor the load factor of the backing HashMap
   * @throws IllegalArgumentException if either argument is negative, or
   *         if loadFactor is POSITIVE_INFINITY or NaN
   */
  public LinkedHashSet(int initialCapacity, float loadFactor)
  {
    super(initialCapacity, loadFactor);
  }

  /**
   * Construct a new HashSet with the same elements as are in the supplied
   * collection (eliminating any duplicates, of course). The backing storage
   * has twice the size of the collection, or the default size of 11,
   * whichever is greater; and the default load factor (0.75).
   *
   * @param c a collection of initial set elements
   * @throws NullPointerException if c is null
   */
  public LinkedHashSet(Collection c)
  {
    super(c);
  }

  /**
   * Helper method which initializes the backing Map.
   *
   * @param capacity the initial capacity
   * @param load the initial load factor
   * @return the backing HashMap
   */
  HashMap init(int capacity, float load)
  {
    return new LinkedHashMap(capacity, load);
  }

}